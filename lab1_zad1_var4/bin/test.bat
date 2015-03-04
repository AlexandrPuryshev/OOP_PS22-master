@echo off

REM запуск программы с несуществующими именами файлов 
Replace_lab1.exe 1.txt 2.txt friend friends
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

REM запуск программы с пустой строкой
Replace_lab1.exe input.txt output.txt "" ff
IF ERRORLEVEL 1 GOTO err

REM запуск программы с верными параметрами
Replace_lab1.exe inputMam.txt output1.txt mam mama
IF ERRORLEVEL 1 GOTO err
FC /B output.txt outputMam.txt

REM запуск программы с верными параметрами
Replace_lab1.exe inputf.txt output2.txt f ff
IF ERRORLEVEL 1 GOTO err
FC /B output.txt outputf.txt

REM запуск программы с верными параметрами
Replace_lab1.exe input.txt output3.txt €блоко груша
IF ERRORLEVEL 1 GOTO err
FC /B output.txt outputGRYSH.txt


ECHO Program testing succeeded :-)
EXIT
:err
ECHO Program testing failed :-(
EXIT

