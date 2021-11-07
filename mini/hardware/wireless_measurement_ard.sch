EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L wireless_measurement_ard-rescue:JDY-08-jdy-08 U2
U 1 1 60F6CD69
P 3150 2100
F 0 "U2" H 3150 3187 60  0000 C CNN
F 1 "JDY-08" H 3150 3081 60  0000 C CNN
F 2 "JDY-08:JDY-08_HandSoldering" H 5000 2000 60  0001 C CNN
F 3 "https://github.com/kichMan/JDY-08" H 5000 2000 60  0001 C CNN
	1    3150 2100
	1    0    0    -1  
$EndComp
$Comp
L wireless_measurement_ard-rescue:MCP16415-gen_lib U3
U 1 1 60F711CF
P 9350 4500
F 0 "U3" H 9350 5015 50  0000 C CNN
F 1 "MCP16415" H 9350 4924 50  0000 C CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 9400 4050 50  0001 C CNN
F 3 "https://ww1.microchip.com/downloads/en/DeviceDoc/MCP1641X-Family-Data-Sheet-DS20006394B.pdf" H 9350 4500 50  0001 C CNN
	1    9350 4500
	1    0    0    -1  
$EndComp
Wire Wire Line
	10250 1550 10350 1550
Wire Wire Line
	10350 1550 10350 1450
Wire Wire Line
	10250 1650 10350 1650
Wire Wire Line
	10350 1650 10350 1750
Connection ~ 10450 1450
Connection ~ 10450 1750
Wire Wire Line
	10450 1750 10650 1750
Wire Wire Line
	10350 1750 10450 1750
Wire Wire Line
	10450 1450 10650 1450
Wire Wire Line
	10350 1450 10450 1450
$Comp
L Device:R R1
U 1 1 60F77736
P 10450 1600
F 0 "R1" H 10520 1646 50  0000 L CNN
F 1 "1R" H 10520 1555 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 10380 1600 50  0001 C CNN
F 3 "~" H 10450 1600 50  0001 C CNN
	1    10450 1600
	1    0    0    -1  
$EndComp
Wire Wire Line
	10650 1750 10650 1650
Wire Wire Line
	10650 1550 10650 1450
Text Notes 8950 1150 0    50   ~ 0
uA current sensing
$Comp
L power:GND #PWR0103
U 1 1 60F86049
P 2450 2900
F 0 "#PWR0103" H 2450 2650 50  0001 C CNN
F 1 "GND" H 2455 2727 50  0000 C CNN
F 2 "" H 2450 2900 50  0001 C CNN
F 3 "" H 2450 2900 50  0001 C CNN
	1    2450 2900
	1    0    0    -1  
$EndComp
Text GLabel 3850 2400 2    50   Input ~ 0
ARD_RX
Text GLabel 3850 2500 2    50   Input ~ 0
ARD_TX
$Comp
L power:+3.3V #PWR0107
U 1 1 60F95D67
P 2450 1350
F 0 "#PWR0107" H 2450 1200 50  0001 C CNN
F 1 "+3.3V" H 2465 1523 50  0000 C CNN
F 2 "" H 2450 1350 50  0001 C CNN
F 3 "" H 2450 1350 50  0001 C CNN
	1    2450 1350
	1    0    0    -1  
$EndComp
Text GLabel 2450 1850 0    50   Input ~ 0
PWRC
Text GLabel 10800 1650 2    50   Input ~ 0
C1_IN
Wire Wire Line
	10650 1650 10800 1650
Wire Wire Line
	10650 1550 10800 1550
Text GLabel 10800 1550 2    50   Input ~ 0
C1_OUT
Text GLabel 8550 4250 0    50   Input ~ 0
VIN
Text GLabel 8550 4350 0    50   Input ~ 0
LBO
Text GLabel 8550 4450 0    50   Input ~ 0
PGT
Text GLabel 8550 4550 0    50   Input ~ 0
VFB
$Comp
L power:+3.3V #PWR0112
U 1 1 60FD01FA
P 8200 4650
F 0 "#PWR0112" H 8200 4500 50  0001 C CNN
F 1 "+3.3V" H 8215 4823 50  0000 C CNN
F 2 "" H 8200 4650 50  0001 C CNN
F 3 "" H 8200 4650 50  0001 C CNN
	1    8200 4650
	0    -1   -1   0   
$EndComp
Wire Wire Line
	8550 4550 8950 4550
Wire Wire Line
	8950 4350 8550 4350
Wire Wire Line
	8550 4250 8950 4250
Text GLabel 9750 4350 2    50   Input ~ 0
VIN
$Comp
L Device:L L1
U 1 1 60FD4756
P 9900 4650
F 0 "L1" V 9950 4500 50  0000 C CNN
F 1 "4.7uH" V 10000 4650 50  0000 C CNN
F 2 "Inductor_SMD:L_Bourns-SRN4018" H 9900 4650 50  0001 C CNN
F 3 "~" H 9900 4650 50  0001 C CNN
	1    9900 4650
	0    1    1    0   
$EndComp
Text GLabel 10050 4650 2    50   Input ~ 0
VIN
$Comp
L power:GND #PWR0113
U 1 1 60FD5713
P 10100 4500
F 0 "#PWR0113" H 10100 4250 50  0001 C CNN
F 1 "GND" H 10105 4327 50  0000 C CNN
F 2 "" H 10100 4500 50  0001 C CNN
F 3 "" H 10100 4500 50  0001 C CNN
	1    10100 4500
	0    -1   -1   0   
$EndComp
Wire Wire Line
	9750 4450 10100 4450
Wire Wire Line
	10100 4450 10100 4500
Wire Wire Line
	9750 4550 10100 4550
Wire Wire Line
	10100 4550 10100 4500
Connection ~ 10100 4500
Text GLabel 9750 4250 2    50   Input ~ 0
VIN
$Comp
L Device:C C1
U 1 1 60FD723B
P 8600 4800
F 0 "C1" H 8400 4850 50  0000 L CNN
F 1 "10uF" H 8400 4750 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 8638 4650 50  0001 C CNN
F 3 "~" H 8600 4800 50  0001 C CNN
F 4 "C96446" H 8600 4800 50  0001 C CNN "LCSC"
	1    8600 4800
	1    0    0    -1  
$EndComp
Connection ~ 8600 4650
$Comp
L Device:C C2
U 1 1 60FD8008
P 8850 4800
F 0 "C2" H 8965 4846 50  0000 L CNN
F 1 "1uF" H 8965 4755 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 8888 4650 50  0001 C CNN
F 3 "~" H 8850 4800 50  0001 C CNN
F 4 "C15849" H 8850 4800 50  0001 C CNN "LCSC"
	1    8850 4800
	1    0    0    -1  
$EndComp
Connection ~ 8850 4650
Wire Wire Line
	8850 4650 8950 4650
$Comp
L power:GND #PWR0114
U 1 1 60FD8198
P 8700 5000
F 0 "#PWR0114" H 8700 4750 50  0001 C CNN
F 1 "GND" H 8705 4827 50  0000 C CNN
F 2 "" H 8700 5000 50  0001 C CNN
F 3 "" H 8700 5000 50  0001 C CNN
	1    8700 5000
	1    0    0    -1  
$EndComp
Wire Wire Line
	8600 4950 8600 5000
Wire Wire Line
	8600 4650 8850 4650
Wire Wire Line
	8850 5000 8850 4950
Text GLabel 8950 5400 0    50   Input ~ 0
VIN
$Comp
L Device:C C3
U 1 1 60FDA2A7
P 9050 5600
F 0 "C3" H 9165 5646 50  0000 L CNN
F 1 "1uF" H 9165 5555 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 9088 5450 50  0001 C CNN
F 3 "~" H 9050 5600 50  0001 C CNN
F 4 "C15849" H 9050 5600 50  0001 C CNN "LCSC"
	1    9050 5600
	1    0    0    -1  
$EndComp
$Comp
L Device:C C4
U 1 1 60FDA596
P 9400 5600
F 0 "C4" H 9515 5646 50  0000 L CNN
F 1 "10uF" H 9515 5555 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 9438 5450 50  0001 C CNN
F 3 "~" H 9400 5600 50  0001 C CNN
F 4 "C96446" H 9400 5600 50  0001 C CNN "LCSC"
	1    9400 5600
	1    0    0    -1  
$EndComp
Wire Wire Line
	8950 5400 9050 5400
Wire Wire Line
	9400 5400 9400 5450
Wire Wire Line
	9050 5400 9050 5450
Connection ~ 9050 5400
Wire Wire Line
	9050 5400 9400 5400
$Comp
L power:GND #PWR0115
U 1 1 60FDC426
P 9200 5800
F 0 "#PWR0115" H 9200 5550 50  0001 C CNN
F 1 "GND" H 9205 5627 50  0000 C CNN
F 2 "" H 9200 5800 50  0001 C CNN
F 3 "" H 9200 5800 50  0001 C CNN
	1    9200 5800
	1    0    0    -1  
$EndComp
Wire Wire Line
	9050 5750 9200 5750
Wire Wire Line
	9200 5750 9200 5800
Wire Wire Line
	9200 5750 9400 5750
Connection ~ 9200 5750
$Comp
L Device:R R4
U 1 1 60FE08B8
P 8300 4800
F 0 "R4" H 8400 4800 50  0000 L CNN
F 1 "866k" H 8400 4900 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 8230 4800 50  0001 C CNN
F 3 "~" H 8300 4800 50  0001 C CNN
F 4 "C101220" H 8300 4800 50  0001 C CNN "LCSC"
	1    8300 4800
	-1   0    0    1   
$EndComp
Wire Wire Line
	8600 5000 8700 5000
$Comp
L Device:R R5
U 1 1 60FE1FFB
P 8300 5250
F 0 "R5" H 8400 5250 50  0000 L CNN
F 1 "360k" H 8400 5350 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 8230 5250 50  0001 C CNN
F 3 "~" H 8300 5250 50  0001 C CNN
F 4 "C23146" H 8300 5250 50  0001 C CNN "LCSC"
	1    8300 5250
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR0116
U 1 1 60FE242E
P 8300 5500
F 0 "#PWR0116" H 8300 5250 50  0001 C CNN
F 1 "GND" H 8305 5327 50  0000 C CNN
F 2 "" H 8300 5500 50  0001 C CNN
F 3 "" H 8300 5500 50  0001 C CNN
	1    8300 5500
	1    0    0    -1  
$EndComp
Text GLabel 8200 5050 0    50   Input ~ 0
VFB
Wire Wire Line
	8200 4650 8300 4650
Connection ~ 8300 4650
Wire Wire Line
	8300 4650 8600 4650
Wire Wire Line
	8200 5050 8300 5050
Wire Wire Line
	8300 5050 8300 5100
Wire Wire Line
	8300 4950 8300 5050
Connection ~ 8300 5050
Wire Wire Line
	8300 5400 8300 5500
Connection ~ 8700 5000
Wire Wire Line
	8700 5000 8850 5000
$Comp
L power:+3.3V #PWR0118
U 1 1 6100B7A7
P 5100 3450
F 0 "#PWR0118" H 5100 3300 50  0001 C CNN
F 1 "+3.3V" H 5115 3623 50  0000 C CNN
F 2 "" H 5100 3450 50  0001 C CNN
F 3 "" H 5100 3450 50  0001 C CNN
	1    5100 3450
	1    0    0    -1  
$EndComp
$Comp
L Device:C C6
U 1 1 610112E3
P 5350 3700
F 0 "C6" H 5400 3800 50  0000 L CNN
F 1 "0.1uF" H 5400 3600 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 5388 3550 50  0001 C CNN
F 3 "~" H 5350 3700 50  0001 C CNN
F 4 "C14663" H 5350 3700 50  0001 C CNN "LCSC"
	1    5350 3700
	1    0    0    -1  
$EndComp
$Comp
L Device:C C5
U 1 1 61011D4D
P 5100 3700
F 0 "C5" H 4850 3750 50  0000 L CNN
F 1 "4.7uF" H 4800 3650 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 5138 3550 50  0001 C CNN
F 3 "~" H 5100 3700 50  0001 C CNN
F 4 "C19666" H 5100 3700 50  0001 C CNN "LCSC"
	1    5100 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	5100 3550 5100 3450
Wire Wire Line
	5350 3550 5100 3550
$Comp
L power:GND #PWR0119
U 1 1 61016AAB
P 5250 3850
F 0 "#PWR0119" H 5250 3600 50  0001 C CNN
F 1 "GND" H 5255 3677 50  0000 C CNN
F 2 "" H 5250 3850 50  0001 C CNN
F 3 "" H 5250 3850 50  0001 C CNN
	1    5250 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	5100 3850 5250 3850
Connection ~ 5250 3850
Wire Wire Line
	5250 3850 5350 3850
Text GLabel 3850 1300 2    50   Input ~ 0
STATUS
Connection ~ 5100 3550
$Comp
L power:GND #PWR0121
U 1 1 610243BD
P 3400 3900
F 0 "#PWR0121" H 3400 3650 50  0001 C CNN
F 1 "GND" H 3405 3727 50  0000 C CNN
F 2 "" H 3400 3900 50  0001 C CNN
F 3 "" H 3400 3900 50  0001 C CNN
	1    3400 3900
	1    0    0    -1  
$EndComp
Text GLabel 2900 3900 0    50   Input ~ 0
C2D
Text GLabel 2900 3800 0    50   Input ~ 0
C2CK
Wire Wire Line
	8550 4450 8950 4450
$Comp
L wireless_measurement_ard-rescue:EFM8LB1-MCU_SiliconLabs U1
U 1 1 611E9E7B
P 5850 2000
F 0 "U1" H 5850 3015 50  0000 C CNN
F 1 "EFM8LB1" H 5850 2924 50  0000 C CNN
F 2 "Package_DFN_QFN:QFN-32-1EP_4x4mm_P0.4mm_EP2.9x2.9mm" H 5900 2200 50  0001 C CNN
F 3 "" H 5900 2200 50  0001 C CNN
	1    5850 2000
	1    0    0    -1  
$EndComp
Text GLabel 6450 1550 2    50   Input ~ 0
ARD_TX
Text GLabel 6450 1650 2    50   Input ~ 0
ARD_RX
$Comp
L power:GND #PWR0108
U 1 1 611EDCB4
P 5850 3000
F 0 "#PWR0108" H 5850 2750 50  0001 C CNN
F 1 "GND" H 5855 2827 50  0000 C CNN
F 2 "" H 5850 3000 50  0001 C CNN
F 3 "" H 5850 3000 50  0001 C CNN
	1    5850 3000
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0109
U 1 1 611EE56A
P 4900 1250
F 0 "#PWR0109" H 4900 1100 50  0001 C CNN
F 1 "+3.3V" H 4915 1423 50  0000 C CNN
F 2 "" H 4900 1250 50  0001 C CNN
F 3 "" H 4900 1250 50  0001 C CNN
	1    4900 1250
	1    0    0    -1  
$EndComp
Text GLabel 4850 1550 0    50   Input ~ 0
C2CK
Text GLabel 5250 1650 0    50   Input ~ 0
C2D
Text GLabel 6450 2150 2    50   Input ~ 0
PWRC
Text GLabel 6450 2250 2    50   Input ~ 0
STATUS
Text GLabel 5250 2750 0    50   Input ~ 0
GAIN
Text GLabel 6450 2450 2    50   Input ~ 0
A2
$Comp
L power:GND #PWR0104
U 1 1 61019046
P 6700 3700
F 0 "#PWR0104" H 6700 3450 50  0001 C CNN
F 1 "GND" H 6705 3527 50  0000 C CNN
F 2 "" H 6700 3700 50  0001 C CNN
F 3 "" H 6700 3700 50  0001 C CNN
	1    6700 3700
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R3
U 1 1 6101884F
P 6550 3700
F 0 "R3" V 6650 3650 50  0000 L CNN
F 1 "1k" V 6450 3650 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 6480 3700 50  0001 C CNN
F 3 "~" H 6550 3700 50  0001 C CNN
	1    6550 3700
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D1
U 1 1 61017CC7
P 6250 3700
F 0 "D1" H 6250 3600 50  0000 C CNN
F 1 "LED" H 6250 3800 50  0000 C CNN
F 2 "LED_SMD:LED_0603_1608Metric" H 6250 3700 50  0001 C CNN
F 3 "~" H 6250 3700 50  0001 C CNN
	1    6250 3700
	-1   0    0    1   
$EndComp
Text GLabel 6100 3700 0    50   Input ~ 0
LED
Text GLabel 6450 1950 2    50   Input ~ 0
LED
$Comp
L Connector_Generic:Conn_02x03_Odd_Even J2
U 1 1 6127F01E
P 3100 3800
F 0 "J2" H 3150 4117 50  0000 C CNN
F 1 "Tag-Connect" H 3150 4026 50  0000 C CNN
F 2 "Connector:Tag-Connect_TC2030-IDC-NL_2x03_P1.27mm_Vertical" H 3100 3800 50  0001 C CNN
F 3 "~" H 3100 3800 50  0001 C CNN
	1    3100 3800
	1    0    0    -1  
$EndComp
$Comp
L Device:R R6
U 1 1 6128E69D
P 4900 1400
F 0 "R6" V 5000 1350 50  0000 L CNN
F 1 "1k" V 4800 1350 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad0.98x0.95mm_HandSolder" V 4830 1400 50  0001 C CNN
F 3 "~" H 4900 1400 50  0001 C CNN
F 4 "C21190" V 4900 1400 50  0001 C CNN "LCSC"
	1    4900 1400
	1    0    0    -1  
$EndComp
Wire Wire Line
	5250 1350 5050 1350
Wire Wire Line
	5050 1350 5050 1250
Wire Wire Line
	5050 1250 4900 1250
Connection ~ 4900 1250
Wire Wire Line
	5250 1450 5050 1450
Wire Wire Line
	5050 1450 5050 1350
Connection ~ 5050 1350
Wire Wire Line
	4850 1550 4900 1550
Wire Wire Line
	5250 1550 4900 1550
Connection ~ 4900 1550
Text GLabel 2900 3700 0    50   Input ~ 0
BATT
$Comp
L Device:R R7
U 1 1 6131256B
P 8250 1900
F 0 "R7" V 8350 1850 50  0000 L CNN
F 1 "110k" V 8150 1850 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad0.98x0.95mm_HandSolder" V 8180 1900 50  0001 C CNN
F 3 "~" H 8250 1900 50  0001 C CNN
F 4 "C25805" V 8250 1900 50  0001 C CNN "LCSC"
	1    8250 1900
	1    0    0    -1  
$EndComp
Text GLabel 9450 1900 2    50   Input ~ 0
MAX_SHDN
Text GLabel 6450 1850 2    50   Input ~ 0
A4
$Comp
L Device:C C7
U 1 1 6152B86D
P 5250 1100
F 0 "C7" H 5000 1150 50  0000 L CNN
F 1 "4.7uF" H 4950 1050 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.08x0.95mm_HandSolder" H 5288 950 50  0001 C CNN
F 3 "~" H 5250 1100 50  0001 C CNN
F 4 "C19666" H 5250 1100 50  0001 C CNN "LCSC"
	1    5250 1100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0110
U 1 1 615A23E8
P 9450 1800
F 0 "#PWR0110" H 9450 1550 50  0001 C CNN
F 1 "GND" H 9455 1627 50  0000 C CNN
F 2 "" H 9450 1800 50  0001 C CNN
F 3 "" H 9450 1800 50  0001 C CNN
	1    9450 1800
	0    -1   -1   0   
$EndComp
$Comp
L power:+3.3V #PWR0111
U 1 1 615A4E84
P 8250 1750
F 0 "#PWR0111" H 8250 1600 50  0001 C CNN
F 1 "+3.3V" H 8265 1923 50  0000 C CNN
F 2 "" H 8250 1750 50  0001 C CNN
F 3 "" H 8250 1750 50  0001 C CNN
	1    8250 1750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0120
U 1 1 615A53CD
P 8250 2400
F 0 "#PWR0120" H 8250 2150 50  0001 C CNN
F 1 "GND" H 8255 2227 50  0000 C CNN
F 2 "" H 8250 2400 50  0001 C CNN
F 3 "" H 8250 2400 50  0001 C CNN
	1    8250 2400
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0122
U 1 1 615A8A4D
P 8750 1900
F 0 "#PWR0122" H 8750 1750 50  0001 C CNN
F 1 "+3.3V" H 8765 2073 50  0000 C CNN
F 2 "" H 8750 1900 50  0001 C CNN
F 3 "" H 8750 1900 50  0001 C CNN
	1    8750 1900
	0    -1   -1   0   
$EndComp
Text GLabel 8750 1600 0    50   Input ~ 0
RS+
Text GLabel 9450 1600 2    50   Input ~ 0
RS-
Wire Wire Line
	8250 2100 8250 2050
Text GLabel 10250 1650 0    50   Input ~ 0
RS+
Text GLabel 10250 1550 0    50   Input ~ 0
RS-
Text GLabel 8750 1700 0    50   Input ~ 0
GAIN
Text GLabel 8750 1800 0    50   Input ~ 0
A0
Text GLabel 6450 2550 2    50   Input ~ 0
A1
Text GLabel 6450 2750 2    50   Input ~ 0
MAX_SHDN
Text GLabel 6450 2650 2    50   Input ~ 0
A0
$Comp
L wireless_measurement_ard-rescue:MAX40204-ben_common U4
U 1 1 61604BD6
P 9100 1750
F 0 "U4" H 9100 2125 50  0000 C CNN
F 1 "MAX40204" H 9100 2034 50  0000 C CNN
F 2 "ben_common:BGA-8_4x2_1.468x0.848mm" H 9100 1750 50  0001 C CNN
F 3 "" H 9100 1750 50  0001 C CNN
	1    9100 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	7900 2050 8050 2050
Connection ~ 8250 2050
Text GLabel 2600 5050 0    50   Input ~ 0
A4
Wire Wire Line
	2400 5250 2600 5250
Wire Wire Line
	2400 5150 2600 5150
$Comp
L power:+3.3V #PWR0105
U 1 1 612F90A4
P 2400 5150
F 0 "#PWR0105" H 2400 5000 50  0001 C CNN
F 1 "+3.3V" V 2450 5350 50  0000 C CNN
F 2 "" H 2400 5150 50  0001 C CNN
F 3 "" H 2400 5150 50  0001 C CNN
	1    2400 5150
	0    -1   -1   0   
$EndComp
Text GLabel 3600 5200 0    50   Input ~ 0
VIN
Text GLabel 4000 5100 2    50   Input ~ 0
BATT
$Comp
L Switch:SW_SPDT SW1
U 1 1 61043960
P 3800 5200
F 0 "SW1" H 3800 5485 50  0000 C CNN
F 1 "SW_SPDT" H 3800 5394 50  0000 C CNN
F 2 "ben_common:SW_SPDT_CK-JS102011SAQN" H 3800 5200 50  0001 C CNN
F 3 "~" H 3800 5200 50  0001 C CNN
	1    3800 5200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0117
U 1 1 60FE7F19
P 3550 4650
F 0 "#PWR0117" H 3550 4400 50  0001 C CNN
F 1 "GND" H 3555 4477 50  0000 C CNN
F 2 "" H 3550 4650 50  0001 C CNN
F 3 "" H 3550 4650 50  0001 C CNN
	1    3550 4650
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x02 Battery1
U 1 1 60FE7457
P 3750 4550
F 0 "Battery1" H 3830 4542 50  0000 L CNN
F 1 "Conn_01x02" H 3830 4451 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x02_P2.54mm_Vertical" H 3750 4550 50  0001 C CNN
F 3 "~" H 3750 4550 50  0001 C CNN
	1    3750 4550
	1    0    0    -1  
$EndComp
Text GLabel 3550 4550 0    50   Input ~ 0
BATT
Text GLabel 2600 4650 0    50   Input ~ 0
C1_OUT
Text GLabel 2600 4550 0    50   Input ~ 0
C1_IN
$Comp
L power:GND #PWR0106
U 1 1 60F9306D
P 2400 5250
F 0 "#PWR0106" H 2400 5000 50  0001 C CNN
F 1 "GND" V 2400 5050 50  0000 C CNN
F 2 "" H 2400 5250 50  0001 C CNN
F 3 "" H 2400 5250 50  0001 C CNN
	1    2400 5250
	0    1    1    0   
$EndComp
Text GLabel 2600 4950 0    50   Input ~ 0
A2
$Comp
L Connector_Generic:Conn_01x08 J1
U 1 1 60FC6837
P 2800 4850
F 0 "J1" H 2880 4842 50  0000 L CNN
F 1 "Conn_01x08" H 2880 4751 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x08_P2.54mm_Horizontal" H 2800 4850 50  0001 C CNN
F 3 "~" H 2800 4850 50  0001 C CNN
	1    2800 4850
	1    0    0    -1  
$EndComp
Wire Wire Line
	10250 2750 10350 2750
Wire Wire Line
	10350 2750 10350 2650
Wire Wire Line
	10250 2850 10350 2850
Wire Wire Line
	10350 2850 10350 2950
Connection ~ 10450 2650
Connection ~ 10450 2950
Wire Wire Line
	10450 2950 10650 2950
Wire Wire Line
	10350 2950 10450 2950
Wire Wire Line
	10450 2650 10650 2650
Wire Wire Line
	10350 2650 10450 2650
$Comp
L Device:R R2
U 1 1 616414BC
P 10450 2800
F 0 "R2" H 10520 2846 50  0000 L CNN
F 1 "1R" H 10520 2755 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" V 10380 2800 50  0001 C CNN
F 3 "~" H 10450 2800 50  0001 C CNN
	1    10450 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	10650 2950 10650 2850
Wire Wire Line
	10650 2750 10650 2650
Text GLabel 10800 2850 2    50   Input ~ 0
C2_IN
Wire Wire Line
	10650 2850 10800 2850
Wire Wire Line
	10650 2750 10800 2750
Text GLabel 10800 2750 2    50   Input ~ 0
C2_OUT
Text GLabel 9450 2600 2    50   Input ~ 0
MAX_SHDN2
$Comp
L power:GND #PWR0101
U 1 1 616414D5
P 9450 2500
F 0 "#PWR0101" H 9450 2250 50  0001 C CNN
F 1 "GND" H 9455 2327 50  0000 C CNN
F 2 "" H 9450 2500 50  0001 C CNN
F 3 "" H 9450 2500 50  0001 C CNN
	1    9450 2500
	0    -1   -1   0   
$EndComp
$Comp
L power:+3.3V #PWR0123
U 1 1 616414E7
P 8750 2600
F 0 "#PWR0123" H 8750 2450 50  0001 C CNN
F 1 "+3.3V" H 8765 2773 50  0000 C CNN
F 2 "" H 8750 2600 50  0001 C CNN
F 3 "" H 8750 2600 50  0001 C CNN
	1    8750 2600
	0    -1   -1   0   
$EndComp
Text GLabel 8750 2300 0    50   Input ~ 0
RS2+
Text GLabel 9450 2300 2    50   Input ~ 0
RS2-
Text GLabel 10250 2850 0    50   Input ~ 0
RS2+
Text GLabel 10250 2750 0    50   Input ~ 0
RS2-
Text GLabel 8750 2400 0    50   Input ~ 0
GAIN2
$Comp
L wireless_measurement_ard-rescue:MAX40204-ben_common U5
U 1 1 616414F4
P 9100 2450
F 0 "U5" H 9100 2825 50  0000 C CNN
F 1 "MAX40204" H 9100 2734 50  0000 C CNN
F 2 "ben_common:BGA-8_4x2_1.468x0.848mm" H 9100 2450 50  0001 C CNN
F 3 "" H 9100 2450 50  0001 C CNN
	1    9100 2450
	1    0    0    -1  
$EndComp
Text GLabel 7900 2050 0    50   Input ~ 0
HALF
$Comp
L Device:R R8
U 1 1 61316095
P 8250 2250
F 0 "R8" V 8350 2200 50  0000 L CNN
F 1 "110k" V 8150 2200 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad0.98x0.95mm_HandSolder" V 8180 2250 50  0001 C CNN
F 3 "~" H 8250 2250 50  0001 C CNN
F 4 "C25805" V 8250 2250 50  0001 C CNN "LCSC"
	1    8250 2250
	1    0    0    -1  
$EndComp
Text GLabel 9450 1700 2    50   Input ~ 0
HALF
Text GLabel 9450 2400 2    50   Input ~ 0
HALF
Text GLabel 8750 2500 0    50   Input ~ 0
A1
Text GLabel 2600 4850 0    50   Input ~ 0
C2_OUT
Text GLabel 2600 4750 0    50   Input ~ 0
C2_IN
Text GLabel 5250 2650 0    50   Input ~ 0
GAIN2
Text GLabel 5250 2550 0    50   Input ~ 0
MAX_SHDN2
$Comp
L power:GND #PWR0102
U 1 1 616FC7EB
P 5250 950
F 0 "#PWR0102" H 5250 700 50  0001 C CNN
F 1 "GND" H 5255 777 50  0000 C CNN
F 2 "" H 5250 950 50  0001 C CNN
F 3 "" H 5250 950 50  0001 C CNN
	1    5250 950 
	-1   0    0    1   
$EndComp
$Comp
L wireless_measurement_ard-rescue:Logo-ben_common U6
U 1 1 615ED4AF
P 6250 850
F 0 "U6" H 6378 871 50  0000 L CNN
F 1 "Logo" H 6378 780 50  0000 L CNN
F 2 "icons:icon" H 6250 850 50  0001 C CNN
F 3 "" H 6250 850 50  0001 C CNN
	1    6250 850 
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0124
U 1 1 6178870C
P 8800 3150
F 0 "#PWR0124" H 8800 3000 50  0001 C CNN
F 1 "+3.3V" H 8815 3323 50  0000 C CNN
F 2 "" H 8800 3150 50  0001 C CNN
F 3 "" H 8800 3150 50  0001 C CNN
	1    8800 3150
	1    0    0    -1  
$EndComp
$Comp
L Device:C C9
U 1 1 61788713
P 9050 3400
F 0 "C9" H 9100 3500 50  0000 L CNN
F 1 "0.1uF" H 9100 3300 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.08x0.95mm_HandSolder" H 9088 3250 50  0001 C CNN
F 3 "~" H 9050 3400 50  0001 C CNN
F 4 "C14663" H 9050 3400 50  0001 C CNN "LCSC"
	1    9050 3400
	1    0    0    -1  
$EndComp
$Comp
L Device:C C8
U 1 1 6178871A
P 8800 3400
F 0 "C8" H 8550 3450 50  0000 L CNN
F 1 "4.7uF" H 8500 3350 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.08x0.95mm_HandSolder" H 8838 3250 50  0001 C CNN
F 3 "~" H 8800 3400 50  0001 C CNN
F 4 "C19666" H 8800 3400 50  0001 C CNN "LCSC"
	1    8800 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	8800 3250 8800 3150
Wire Wire Line
	9050 3250 8800 3250
$Comp
L power:GND #PWR0125
U 1 1 61788722
P 8950 3550
F 0 "#PWR0125" H 8950 3300 50  0001 C CNN
F 1 "GND" H 8955 3377 50  0000 C CNN
F 2 "" H 8950 3550 50  0001 C CNN
F 3 "" H 8950 3550 50  0001 C CNN
	1    8950 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	8800 3550 8950 3550
Connection ~ 8950 3550
Wire Wire Line
	8950 3550 9050 3550
Connection ~ 8800 3250
Text GLabel 7900 1850 0    50   Input ~ 0
A5
Wire Wire Line
	8050 2050 8050 1850
Wire Wire Line
	8050 1850 7900 1850
Connection ~ 8050 2050
Wire Wire Line
	8050 2050 8250 2050
Text GLabel 6450 2350 2    50   Input ~ 0
A5
$EndSCHEMATC