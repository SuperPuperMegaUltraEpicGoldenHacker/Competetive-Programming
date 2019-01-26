::@echo off   
 
set compile=g++ -std=c++11 -O2 -Wl,--stack=268435456
%compile% -o Fast Fast.cpp && %compile% -o Slow Slow.cpp && %compile% -o Gen Gen.cpp && echo Compiled || echo Compliation failed! && exit
 
 
set /a i=1
:loop
  set /a i=%i%+1
  if %i% EQU 1001 (
    echo Not Found
    exit
  )
  echo %i%           
  Gen.exe > Input.txt
  Slow.exe < Input.txt > Slow.out
  Fast.exe < Input.txt > Fast.out
  fc Slow.out Fast.out
  if errorlevel 1
  (
    echo FOUND
    exit
  )
goto loop