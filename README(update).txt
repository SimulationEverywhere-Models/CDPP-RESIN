For the model specification(Part-I and II)
Please see assignment1-pengxie.zip

1.The files I created include:
computer.h computer.cpp 	(atomic model-Comouter)
count.h count.cpp		(atomic model-Count)
storetank.h storetank.cpp 	(atomic model-Storetank)
mixtank.h mixtank.cpp		(atomic model-Mixtank)
mouldtank.h mould.cpp		(atomic model-Mouldtank)
atomic.h (needed)
register.cpp
makefile

democomputer.bat
demostk.bat
demostoretank.bat
demomixtank.bat
demomouldtankbat
democsystem.bat
demopline.bat
demo.bat

*.ev and *.ma (the details as follows)
2.Model Structure:
Atmoic model Count and Storetank make up the coupled model Stk.
Atomic model Computer make up the model Control. 
Atomic mode Mixtank and Stk and Mouldtank make up the coupled model Pline.
Pline and Computer make up the top model.

Each atomic model and coupled model has passed the test according to 
the test strategy of my assignment.
The file names I used include:				(DEMO)

computer.ma		computer.ev        		(democomputer.bat)
Stk.ma		    Stk.ev(Stank coupled model)		(demoStk.bat)
storetank.ma	storetank.ev       			(demostoretank.bat)
mixtank.ma		mixtank.ev			(demomixtank.bat)
mouldtank.ma	mouldtank.ev				(demomouldtank.bat)
csystem.ma      csystem.ev(control coupled model)	(democsystem.bat)
pline.ma        pline.ev(production line model)		(demopline.bat)
resin.ma        resin.ev(Top Coupled model)		(demo.bat)

In order to demonstrate top coupled model,
please run demo.bat    the log file is resin.log.
For each model composed of the system, please run demoXXXX.bat for the corresponding modelXXXX.

Peng Xie
258879
xie_peng@hotmail.com
 





   
