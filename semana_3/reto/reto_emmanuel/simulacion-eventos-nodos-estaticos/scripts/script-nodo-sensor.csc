set ant 999
set ite 0
battery set 100

atget id id
getpos2 lonSen latSen

loop
wait 100

read mens
rdata mens tipo valor

if((tipo=="hola") && (ant == 999))
	inc ite	
   set ant valor
   data mens tipo id
   send mens * valor
end

if(tipo=="alerta")
	inc ite	
   send mens ant
end
delay 1000
areadsensor tempSen
rdata tempSen SensTipo idSens temp

if( temp>30)
	inc ite	
   data mens "alerta" lonSen latSen
   send mens ant
end

battery bat
if(bat<5)
	data mens "critico" lonSen latSen
	send mens ant
end

if (tipo=="stop")
	data mens "stop"
	send mens * valor
	cprint "Para sensor: " id
	wait 1000
	stop
end


print ite
if (ite >= 1000)
	data mens "stop"
	send mens
	cprint "Para sensor: " id
	wait 1000
	stop
end