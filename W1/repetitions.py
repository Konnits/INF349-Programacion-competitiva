cadena = input("")
cont=1
max_cont=0
letra_anterior=""

for letra in cadena:
    if letra== letra_anterior:
        cont+=1
    else:
        cont=1

    if max_cont<cont:
        max_cont= cont
    letra_anterior=letra
print(max_cont)