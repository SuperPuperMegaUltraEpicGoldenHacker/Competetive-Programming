::@echo off   

set compile=g++ -std=c++11 -O2 -Wl,--stack=268435456
%compile% -o fast fast.cpp && %compile% -o slow slow.cpp && %compile% -o gen gen.cpp && echo Compiled || echo Compliation failed! && exit


set /a i=1
:loop
  set /a i=%i% + 1
  if %i% EQU 1001 (
    echo not found
    exit
  )
  echo %i%           
  gen.exe > t.in
  slow.exe < t.in > slow.out
  fast.exe < t.in > fast.out
  fc slow.out fast.out
  if errorlevel 1 (
    echo FOUND
    exit
  )
       
goto loop          
  
