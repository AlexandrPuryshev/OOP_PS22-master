@echo off

REM запуск программы с несуществующими именами файлов 
Replace_lab1.exe IncorrectFile.txt NoOpenFile.txt friend friends
IF ERRORLEVEL 1 GOTO err

REM запуск программы с несуществующими именами файлов 
Replace_lab1.exe "" output.txt  friend friends
IF ERRORLEVEL 1 GOTO err

REM запуск программы с пустой строкой
Replace_lab1.exe input.txt output.txt "" ff
IF ERRORLEVEL 1 GOTO err

REM запуск программы с несуществующими именами файлов 
Replace_lab1.exe input.txt "" friend friends
IF ERRORLEVEL 1 GOTO err

REM запуск программы с неверными именами искомой строки
Replace_lab1.exe input.txt output.txt gavgav friends
IF ERRORLEVEL 1 GOTO err

REM запуск программы с неполными параметрами
Replace_lab1.exe input.txt output.txt friends
IF ERRORLEVEL 1 GOTO err

REM запуск программы с неполными параметрами
Replace_lab1.exe input.txt friends
IF ERRORLEVEL 1 GOTO err

REM запуск программы с неполными параметрами
Replace_lab1.exe input.txt
IF ERRORLEVEL 1 GOTO err

REM запуск программы с верными параметрами
Replace_lab1.exe inputMam.txt output1.txt ma mama
IF ERRORLEVEL 1 GOTO err
FC /B output1.txt outputMam.txt

REM запуск программы с верными параметрами
Replace_lab1.exe input_fffmafff.txt output4.txt ma mama
IF ERRORLEVEL 1 GOTO err
FC /B output4.txt output_ffffmafff

REM запуск программы с верными параметрами
Replace_lab1.exe inputf.txt output2.txt f ff
IF ERRORLEVEL 1 GOTO err
FC /B output2.txt outputf.txt

REM запуск программы с верными параметрами
Replace_lab1.exe input.txt output3.txt яблоко груша
IF ERRORLEVEL 1 GOTO err
FC /B output3.txt outputGRYSH.txt

REM запуск программы с верными параметрами
Replace_lab1.exe inputOnegin.txt output5.txt "Eвгений Онегин" Красиво
IF ERRORLEVEL 1 GOTO err
FC /B output5.txt outputOnegin.txt


ECHO Program testing succeeded :-)
EXIT
:err
ECHO Program testing failed :-(
EXIT

