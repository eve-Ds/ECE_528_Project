/**
 * @file main.c
 *
 * @brief Main source code for the BLE_UART program.
 *
 * This file contains the main functions used to control Ovo.
 *
 * @author Evelyn Dominguez
 *
 */
#include <inc/ble_uart.h>
#include <stdint.h>
#include <math.h>
#include "msp.h"

#include "inc/Clock.h"
#include "inc/CortexM.h"
#include "inc/EUSCI_A0_UART.h"
#include "inc/Motor.h"
#include "inc/Buzzer.h"
#include "inc/Nokia5110_LCD.h"
#include "inc/Robo_Faces.h"

//Initialize constant PWM duty cycle values for the motors
#define PWM_NOMINAL 3000

void Process_BLE_UART_Data(char BLE_UART_Buffer[])
{
    //when up arrow is pressed robot moves forward and displays image
    if (Check_BLE_UART_Data(BLE_UART_Buffer, "!B51"))
    {
        Motor_Forward(1500,2000);
        Nokia5110_DrawFullImage(Forward_Face);

    }
    //when up arrow is released robot stops and changes back to default image
    else if (Check_BLE_UART_Data(BLE_UART_Buffer, "!B50"))
    {
        Motor_Stop();
        Nokia5110_Clear();
        Nokia5110_DrawFullImage(Ovo_face);

    }

    //when down arrow is pressed robot moves backward and displays an image
    else if (Check_BLE_UART_Data (BLE_UART_Buffer, "!B61"))
    {
        Motor_Backward(900,1505);
        Nokia5110_DrawFullImage(Looking_Back);

    }
    //when down arrow is released robot moves backward
    else if (Check_BLE_UART_Data (BLE_UART_Buffer, "!B60"))
    {
        Motor_Stop();
        Nokia5110_DrawFullImage(Ovo_face);
    }

    //Robot moves left when left arrow is pressed
    else if (Check_BLE_UART_Data(BLE_UART_Buffer, "!B71"))
    {
        Motor_Left(1500,1000);
        Nokia5110_DrawFullImage(Left_Face);
    }
    else if (Check_BLE_UART_Data(BLE_UART_Buffer, "!B70"))
    {
        Motor_Stop();
        Nokia5110_DrawFullImage(Ovo_face);
    }

    //Robot moves right when right arrow is pressed
    else if (Check_BLE_UART_Data(BLE_UART_Buffer, "!B81"))
    {
        Motor_Right(1500,1000);
        Nokia5110_DrawFullImage(Right_Face);
    }
    //Robot stop when right button is released
    else if (Check_BLE_UART_Data(BLE_UART_Buffer, "!B80"))
    {
        Motor_Stop();
        Nokia5110_DrawFullImage(Ovo_face);
    }
    // If button 1 is pressed it follows this movement sequence
    else if (Check_BLE_UART_Data(BLE_UART_Buffer,"!B11"))
    {

        Motor_Forward(900,1505);
        Clock_Delay1ms(2000);
        Motor_Backward(900,1505);
        Clock_Delay1ms(2000);
        Motor_Forward(900,1505);
        Clock_Delay1ms(3000);
        Motor_Right(4000,900);
        Clock_Delay1ms(4000);
        Motor_Stop();
    }
    // If button 2 is pressed Tokyo Drift will play
    else if (Check_BLE_UART_Data(BLE_UART_Buffer,"!B21"))
    {

        Nokia5110_Init();
        Nokia5110_Set_Contrast(0xB8);
        Nokia5110_ClearBuffer();
        Nokia5110_Clear();
        Nokia5110_DrawFullImage(DomToretto);
        //Play_Note_Pattern();
        Buzzer_On();
        Tokyo_Drift();
        Buzzer_Off();
        Nokia5110_Clear();
        Nokia5110_DrawFullImage(Ovo_face);


    }
    else if (Check_BLE_UART_Data(BLE_UART_Buffer,"!B20"))
    {
        Buzzer_Off();
        Nokia5110_Clear();
        Nokia5110_DrawFullImage(Ovo_face);

    }
    else
    {
        printf("BLE UART Command Not Found\n");
    }
}



int main(void)
{

    Clock_Init48MHz();
    DisableInterrupts();

    Buzzer_Init();
    BLE_UART_Init();
    Motor_Init();

    char BLE_UART_Buffer[BLE_UART_BUFFER_SIZE] = {0};
    EnableInterrupts();
    Clock_Delay1ms(1000);
    BLE_UART_Reset();
    BLE_UART_OutString("BLE UART ACTIVE\r\n");

    Nokia5110_Init();
    Nokia5110_Set_Contrast(0xB9);
    Nokia5110_ClearBuffer();
    Nokia5110_Clear();
    Nokia5110_DrawFullImage(Ovo_face);


    while(1)
    {

        int string_size = BLE_UART_InString(BLE_UART_Buffer, BLE_UART_BUFFER_SIZE);

        printf("BLE UART Data: ");
        for (int i = 0; i < string_size; i++)
        {
            printf("%c", BLE_UART_Buffer[i]);
        }
        printf("\n");
        Process_BLE_UART_Data(BLE_UART_Buffer);

    }

}
