# Smart_Speaking_Gloves
It aims at helping deaf and dumb people communicate with others. The user wears a glove and through his hand movement ; detected signals are translated into speech displayed on LCD , mobile application and into audio played through the application. 

used components :
glove
flex sensors
atmega 32
LCD
HC05
resistors 
capacitors

Idea of operation: 
When the user bends a finger the resistance of flex sensor changes and as we use voltage divider circuit this changes the volt read by the pin (ADC).Bent flex sensor is translated into digital 1 and flat flex sensor is digital zero . We used 3 flex sensors, so we have 8 different combinations for sentences to be used like I need help, ....
we used LCD to display translated sentences. We used UART protocol to send these sentences via bluetooth module to be displayed on the mobile and converted into audio.when no finger is bent, it is considered rest position and hence nothing is displayed on LCD and mobile.
