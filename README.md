# symb
Замена выделенных ru/en символов как в Punto Switcher.

Используется в составе примерно такой команды, которая ставится на хоткей:  
```symb "$(xsel -o )" | xsel -i -b; sleep 0.2; xdotool key Control_L+v```
