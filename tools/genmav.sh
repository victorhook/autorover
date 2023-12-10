#!/bin/bash

OUT=include/mavlink
source venv/bin/activate && mavgen.py --lang=C --wire-protocol=1.0 --output=${OUT} mavlink/message_definitions/1.0/common.xml