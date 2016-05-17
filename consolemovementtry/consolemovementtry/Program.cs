﻿using System;
using System.Collections.Generic;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace consolemovementtry
{
    class Program
    {
        static void Main(string[] args)
        {

            string[] ports = SerialPort.GetPortNames();
            for (int i =0; i < ports.Length; i++) {
                Console.WriteLine(ports[i]);
            }
            String portName = Console.ReadLine();
            SerialPort port = new SerialPort(portName, 9600);
            port.Open();

            int base1 = 0;
            int base2 = 180;
            int shoulder = 0;
            int arm = 0;
            int wrist = 0;
            int claw = 0;

            /*
            -1 = shit
            0 = base
            1 = shoulder 
            2 = arm
            */
            int selected = -1;
             

            while (true) { 
                ConsoleKeyInfo keyInfo = Console.ReadKey();
            
                if (keyInfo.Key == ConsoleKey.UpArrow)
                {
                    
                    if (selected == 0)
                    {
                        
                        base1++;
                        base2--;
                        Console.WriteLine("base" +base1.ToString());
                    }
                    else if (selected == 1)
                    {
                        shoulder++;
                        Console.WriteLine("shoulder" + shoulder.ToString());
                    }
                    else if (selected == 2)
                    {
                        arm++;
                        Console.WriteLine("arm" + arm.ToString());
                    }
                    else if (selected == -1)
                    {
                        Console.WriteLine("Nothing selected");
                    }
                    else
                    {
                        Console.WriteLine("unknown call :P");
                    }
                    
                }
                else if (keyInfo.Key == ConsoleKey.DownArrow)
                {
                    if (selected == 0)
                    {

                        base1--;
                        base2++;
                        Console.WriteLine("base" + base1.ToString());
                    }
                    else if (selected == 1)
                    {
                        shoulder--;
                        Console.WriteLine("shoulder" + shoulder.ToString());
                    }
                    else if (selected == 2)
                    {
                        arm--;
                        Console.WriteLine("arm" + arm.ToString());
                    }
                    else if (selected == -1)
                    {
                        Console.WriteLine("Nothing selected");
                    }
                    else
                    {
                        Console.WriteLine("unknown call :P");
                    }

                }
                else if (keyInfo.Key == ConsoleKey.LeftArrow)
                {
                    claw--;
                    Console.WriteLine("claw close "+ claw.ToString());
                    
                }
                else if (keyInfo.Key == ConsoleKey.RightArrow)
                {
                    claw++;
                    Console.WriteLine("claw open "+ claw.ToString());
                   
                }
                else if (keyInfo.Key == ConsoleKey.B)
                {
                    //base
                    Console.WriteLine("base");
                    selected = 0;
                }
                else if (keyInfo.Key == ConsoleKey.S)
                {
                    //shoulder
                    Console.WriteLine("shoulder");
                    selected = 1;
                }
                else if (keyInfo.Key == ConsoleKey.W)
                {
                    //wrist up down
                    Console.WriteLine("arm");
                    selected = 2;
                }
                else if (keyInfo.Key == ConsoleKey.M)
                {
                    //wrist left
                    Console.WriteLine("wrist left");
                    wrist++;
                }
                else if (keyInfo.Key == ConsoleKey.N)
                {
                    //wrist right
                    Console.WriteLine("wrist right");
                    wrist--;
                }
                else if (keyInfo.Key == ConsoleKey.Escape)
                {
                    //wrist right
                    Console.WriteLine("Good bye");
                    System.Threading.Thread.Sleep(1000);
                    break;
                }

                
                String return_ = base1.ToString() + "," + 
                                 base2.ToString() + "," + 
                                 shoulder.ToString() + "," +
                                 arm.ToString() + "," +
                                 wrist.ToString() + "," +
                                 claw.ToString();

                port.Write(return_);
            }
            //Console.ReadLine();
            port.Close();
        }
    }
}
