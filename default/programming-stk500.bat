avrdude -p m2560 -c stk500v2 -P COM348 -v -U lfuse:w:0xE2:m -U hfuse:w:0xD8:m -U efuse:w:0xFF:m -V -U flash:w:stk500v2.hex:i -v -B 2
pause