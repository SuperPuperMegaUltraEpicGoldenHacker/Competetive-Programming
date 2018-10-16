@echo off   
rename %1 fast%1

g++ -std=c++11 -o fast -Wl,--stack=268435456 fast.cpp && g++ -std=c++11 -o slow -Wl,--stack=268435456 slow.cpp && g++ -std=c++11 -o gen -Wl,--stack=268435456 gen.cpp && echo Compiled
pause

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
  
