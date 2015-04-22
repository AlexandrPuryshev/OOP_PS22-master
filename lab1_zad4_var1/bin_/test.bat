@echo off

REM запуск программы c неполными параметрами
RLE.exe pack
IF ERRORLEVEL 1 GOTO err

REM запуск программы c неполными параметрами
RLE.exe pack input_255_crypt.txt
IF ERRORLEVEL 1 GOTO err

REM запуск программы c неполными параметрами
RLE.exe pack input_255_crypt.txt output_255_crypt.txt output_2556_crypt.txt
IF ERRORLEVEL 1 GOTO err

REM запуск программы где символ с кодом 255 pack 
RLE.exe pack input_255_crypt.txt output_255_crypt.txt
IF ERRORLEVEL 1 GOTO err

REM запуск программы где символ с кодом 255 pack, с десятичным числом 
RLE.exe pack input_255_decimal_crypt.txt output_255_decimal_crypt.txt
IF ERRORLEVEL 1 GOTO err

REM запуск программы где символ с кодом 255 unpack
RLE.exe unpack input_255_decrypt.txt output_255_decrypt.txt
IF ERRORLEVEL 1 GOTO err

REM запуск программы где символ с кодом 255, с десятичным числом unpack
RLE.exe unpack input_255_decimal_decrypt.txt output_255_decimal_decrypt.txt
IF ERRORLEVEL 1 GOTO err

REM запуск программы где длина симолов > 256, а именно в файле - 430 pack 
RLE.exe pack input430.txt output430.txt
IF ERRORLEVEL 1 GOTO err

REM запуск программы с запокованием самой себя
RLE.exe pack RLE.exe RLE.exe.packed
IF ERRORLEVEL 1 GOTO err

REM запуск программы с входным пустым файлом unpack 
RLE.exe unpack inputNULL.txt outputNULL.txt
IF ERRORLEVEL 1 GOTO err

REM запуск программы с верными параметрами pack 
RLE.exe pack input_crypt.txt output1.txt
IF ERRORLEVEL 1 GOTO err
FC /B output1.txt output_crypt.txt

REM запуск программы с верными параметрами unpack 
RLE.exe unpack input_decrypt.txt output2.txt
IF ERRORLEVEL 1 GOTO err
FC /B output2.txt output_decrypt.txt

ECHO Program testing succeeded :-)
EXIT
:err
ECHO Program testing failed :-(
EXIT
