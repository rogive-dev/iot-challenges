atget id id
data p "hola" id id
send p

loop
read mens
rdata mens tipo valor1 valor2

if (tipo=="stop")
	data mens "stop"
	send mens * valor
	cprint "Para sensor: " id
	wait 1000
	stop
end
if(tipo == "critico")
	cprint "Nodo descargado en: longitud" valor1 ", latitud: " valor2
	data p "stop"	
	send p
	wait 1000
	stop
end
wait 100