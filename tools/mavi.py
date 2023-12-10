#!/usr/bin/env python3
from serial.tools.list_ports import comports
from pymavlink import mavutil
from pymavlink.mavutil import mavserial
from pymavlink.dialects.v10.ardupilotmega import MAVLink_message, MAVLink_bad_data
import sys


BAUDRATE = 115200


if __name__ == '__main__':
    port = None
    if len(sys.argv) > 1:
        port = sys.argv[1]
    else:
        while port is None:
            ports = [p.device for p in comports()]
            if not ports:
                print('No serial ports available')
                sys.exit(0)
            print('Available ports, choose 1 of following:')
            for i, p in enumerate(ports):
                print(f'  [{i}] {p}')
            index = input('Port number: ')
            try:
                port = ports[int(index)]
            except Exception:
                print(f'{index} is not valid index...')

    from serial import Serial
    s = Serial('/dev/ttyUSB0', baudrate=115200)

    # Create a MAVLink connection
    mav = mavutil.mavlink_connection(port, baud=BAUDRATE)
    # These are very important for the esp32cam adapter!
    mav.port.setRTS(False)
    mav.port.setDTR(False)

    while True:
        try:
            # Wait for a MAVLink message
            msg: MAVLink_message = mav.recv_match(blocking=True)

            if msg:
                if isinstance(msg, MAVLink_bad_data):
                    continue
                # Print the received MAVLink message
                print(f'RX: {msg}')
        except KeyboardInterrupt:
            # Exit the loop if Ctrl+C is pressed
            break

    # Close the serial port when done
    ser.close()