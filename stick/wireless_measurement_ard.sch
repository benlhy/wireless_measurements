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
L wireless_measurement_ard-rescue:JDY-08-jdy-08-wireless_measurement_ard-rescue U2
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
L wireless_measurement_ard-rescue:MCP16415-gen_lib-wireless_measurement_ard-rescue U3
U 1 1 60F711CF
P 9350 4500
F 0 "U3" H 9350 5015 50  0000 C CNN
F 1 "MCP16415" H 9350 4924 50  0000 C CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 9400 4050 50  0001 C CNN
F 3 "https://ww1.microchip.com/downloads/en/DeviceDoc/MCP1641X-Family-Data-Sheet-DS20006394B.pdf" H 9350 4500 50  0001 C CNN
	1    9350 4500
	1    0    0    -1  
$EndComp
$Comp
L wireless_measurement_ard-rescue:MAX9938-gen_lib-wireless_measurement_ard-rescue U5
U 1 1 60F75707
P 8900 2300
F 0 "U5" H 8900 2615 50  0000 C CNN
F 1 "MAX9938" H 8900 2524 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23-5_HandSoldering" H 8900 2000 50  0001 C CNN
F 3 "http://www.farnell.com/datasheets/2345095.pdf" H 8900 2300 50  0001 C CNN
	1    8900 2300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 60F7644E
P 8550 2400
F 0 "#PWR0102" H 8550 2150 50  0001 C CNN
F 1 "GND" H 8555 2227 50  0000 C CNN
F 2 "" H 8550 2400 50  0001 C CNN
F 3 "" H 8550 2400 50  0001 C CNN
	1    8550 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	8550 2200 8400 2200
Text GLabel 8400 2200 0    50   Input ~ 0
A1
Wire Wire Line
	9250 2200 9250 2100
Wire Wire Line
	9250 2300 9250 2400
Connection ~ 9450 2100
Connection ~ 9450 2400
Wire Wire Line
	9450 2400 9650 2400
Wire Wire Line
	9250 2400 9450 2400
Wire Wire Line
	9450 2100 9650 2100
Wire Wire Line
	9250 2100 9450 2100
$Comp
L Device:R R1
U 1 1 60F771F1
P 9450 2250
F 0 "R1" H 9520 2296 50  0000 L CNN
F 1 "5R3" H 9520 2205 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 9380 2250 50  0001 C CNN
F 3 "~" H 9450 2250 50  0001 C CNN
	1    9450 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	9650 2100 9650 2200
Wire Wire Line
	9650 2300 9650 2400
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
$Comp
L Connector_Generic:Conn_01x08 J1
U 1 1 60FC6837
P 9500 3100
F 0 "J1" H 9580 3092 50  0000 L CNN
F 1 "Conn_01x08" H 9580 3001 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x08_P2.54mm_Horizontal" H 9500 3100 50  0001 C CNN
F 3 "~" H 9500 3100 50  0001 C CNN
	1    9500 3100
	1    0    0    -1  
$EndComp
Text GLabel 9300 3400 0    50   Input ~ 0
A3
Text GLabel 9300 3200 0    50   Input ~ 0
A2
$Comp
L power:GND #PWR0106
U 1 1 60F9306D
P 9150 3500
F 0 "#PWR0106" H 9150 3250 50  0001 C CNN
F 1 "GND" H 9155 3327 50  0000 C CNN
F 2 "" H 9150 3500 50  0001 C CNN
F 3 "" H 9150 3500 50  0001 C CNN
	1    9150 3500
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0105
U 1 1 60F92C2D
P 9150 3300
F 0 "#PWR0105" H 9150 3050 50  0001 C CNN
F 1 "GND" H 9155 3127 50  0000 C CNN
F 2 "" H 9150 3300 50  0001 C CNN
F 3 "" H 9150 3300 50  0001 C CNN
	1    9150 3300
	0    1    1    0   
$EndComp
Wire Wire Line
	9150 3300 9300 3300
Wire Wire Line
	9150 3500 9300 3500
Text GLabel 9800 2300 2    50   Input ~ 0
C2_OUT
Text GLabel 9800 2200 2    50   Input ~ 0
C2_IN
Wire Wire Line
	9650 2200 9800 2200
Wire Wire Line
	9650 2300 9800 2300
Text GLabel 9300 2900 0    50   Input ~ 0
C1_IN
Text GLabel 9300 2800 0    50   Input ~ 0
C1_OUT
Text GLabel 9300 3000 0    50   Input ~ 0
C2_IN
Text GLabel 9300 3100 0    50   Input ~ 0
C2_OUT
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
Text GLabel 7450 4300 0    50   Input ~ 0
BATT
$Comp
L Connector_Generic:Conn_01x02 Battery1
U 1 1 60FE7457
P 7650 4300
F 0 "Battery1" H 7730 4292 50  0000 L CNN
F 1 "Conn_01x02" H 7730 4201 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x02_P2.54mm_Vertical" H 7650 4300 50  0001 C CNN
F 3 "~" H 7650 4300 50  0001 C CNN
	1    7650 4300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0117
U 1 1 60FE7F19
P 7450 4400
F 0 "#PWR0117" H 7450 4150 50  0001 C CNN
F 1 "GND" H 7455 4227 50  0000 C CNN
F 2 "" H 7450 4400 50  0001 C CNN
F 3 "" H 7450 4400 50  0001 C CNN
	1    7450 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	8550 2300 8550 2400
Connection ~ 8550 2400
Text GLabel 3650 5500 2    50   Input ~ 0
A0
Text GLabel 3650 5400 2    50   Input ~ 0
A1
Text GLabel 3650 5300 2    50   Input ~ 0
A2
Text GLabel 3650 5200 2    50   Input ~ 0
A3
$Comp
L power:+3.3V #PWR0118
U 1 1 6100B7A7
P 1950 4300
F 0 "#PWR0118" H 1950 4150 50  0001 C CNN
F 1 "+3.3V" H 1965 4473 50  0000 C CNN
F 2 "" H 1950 4300 50  0001 C CNN
F 3 "" H 1950 4300 50  0001 C CNN
	1    1950 4300
	1    0    0    -1  
$EndComp
$Comp
L wireless_measurement_ard-rescue:EFM8LB1x-QFP32-gen_lib-wireless_measurement_ard-rescue U6
U 1 1 6100BE6A
P 3150 4900
F 0 "U6" H 3150 5965 50  0000 C CNN
F 1 "EFM8LB1x-QFP32" H 3150 5874 50  0000 C CNN
F 2 "Package_QFP:LQFP-32_7x7mm_P0.8mm" H 3150 4650 50  0001 C CNN
F 3 "" H 3150 4650 50  0001 C CNN
	1    3150 4900
	1    0    0    -1  
$EndComp
Wire Wire Line
	2650 4400 2200 4400
Text GLabel 2650 4500 0    50   Input ~ 0
C2CK
Text GLabel 2650 4600 0    50   Input ~ 0
C2D
$Comp
L Device:C C6
U 1 1 610112E3
P 2200 4550
F 0 "C6" H 2250 4650 50  0000 L CNN
F 1 "0.1uF" H 2250 4450 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 2238 4400 50  0001 C CNN
F 3 "~" H 2200 4550 50  0001 C CNN
	1    2200 4550
	1    0    0    -1  
$EndComp
Connection ~ 2200 4400
$Comp
L Device:C C5
U 1 1 61011D4D
P 1950 4550
F 0 "C5" H 1700 4600 50  0000 L CNN
F 1 "4.7uF" H 1650 4500 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 1988 4400 50  0001 C CNN
F 3 "~" H 1950 4550 50  0001 C CNN
	1    1950 4550
	1    0    0    -1  
$EndComp
Wire Wire Line
	1950 4400 1950 4300
Wire Wire Line
	2200 4400 1950 4400
Wire Wire Line
	1950 4300 2650 4300
$Comp
L power:GND #PWR0119
U 1 1 61016AAB
P 2100 4700
F 0 "#PWR0119" H 2100 4450 50  0001 C CNN
F 1 "GND" H 2105 4527 50  0000 C CNN
F 2 "" H 2100 4700 50  0001 C CNN
F 3 "" H 2100 4700 50  0001 C CNN
	1    2100 4700
	1    0    0    -1  
$EndComp
Wire Wire Line
	1950 4700 2100 4700
Connection ~ 2100 4700
Wire Wire Line
	2100 4700 2200 4700
Text GLabel 3650 4500 2    50   Input ~ 0
ARD_RX
Text GLabel 3650 4400 2    50   Input ~ 0
ARD_TX
$Comp
L power:GND #PWR0120
U 1 1 61018C99
P 2300 4200
F 0 "#PWR0120" H 2300 3950 50  0001 C CNN
F 1 "GND" H 2305 4027 50  0000 C CNN
F 2 "" H 2300 4200 50  0001 C CNN
F 3 "" H 2300 4200 50  0001 C CNN
	1    2300 4200
	0    1    1    0   
$EndComp
Text GLabel 3850 1300 2    50   Input ~ 0
STATUS
Text GLabel 3650 5100 2    50   Input ~ 0
STATUS
Connection ~ 1950 4300
Connection ~ 1950 4400
$Comp
L Connector_Generic:Conn_01x03 EFM8_Prog1
U 1 1 61023B63
P 7650 3400
F 0 "EFM8_Prog1" H 7730 3442 50  0000 L CNN
F 1 "Conn_01x03" H 7730 3351 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 7650 3400 50  0001 C CNN
F 3 "~" H 7650 3400 50  0001 C CNN
	1    7650 3400
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0121
U 1 1 610243BD
P 7450 3500
F 0 "#PWR0121" H 7450 3250 50  0001 C CNN
F 1 "GND" H 7455 3327 50  0000 C CNN
F 2 "" H 7450 3500 50  0001 C CNN
F 3 "" H 7450 3500 50  0001 C CNN
	1    7450 3500
	1    0    0    -1  
$EndComp
Text GLabel 7450 3400 0    50   Input ~ 0
C2D
Text GLabel 7150 3300 0    50   Input ~ 0
C2CK
Wire Wire Line
	8550 4450 8950 4450
Text GLabel 3650 5000 2    50   Input ~ 0
PWRC
$Comp
L Switch:SW_SPDT SW1
U 1 1 61043960
P 6400 4650
F 0 "SW1" H 6400 4935 50  0000 C CNN
F 1 "SW_SPDT" H 6400 4844 50  0000 C CNN
F 2 "Button_Switch_SMD:SW_SPDT_CK-JS102011SAQN" H 6400 4650 50  0001 C CNN
F 3 "~" H 6400 4650 50  0001 C CNN
	1    6400 4650
	1    0    0    -1  
$EndComp
Text GLabel 6600 4550 2    50   Input ~ 0
BATT
Text GLabel 6200 4650 0    50   Input ~ 0
VIN
$Comp
L Mechanical:MountingHole_Pad H1
U 1 1 6108948B
P 5550 2350
F 0 "H1" H 5650 2399 50  0000 L CNN
F 1 "MountingHole_Pad" H 5650 2308 50  0000 L CNN
F 2 "MountingHole:MountingHole_2.2mm_M2_ISO7380_Pad" H 5550 2350 50  0001 C CNN
F 3 "~" H 5550 2350 50  0001 C CNN
	1    5550 2350
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole_Pad H2
U 1 1 61089F2F
P 5900 2350
F 0 "H2" H 6000 2399 50  0000 L CNN
F 1 "MountingHole_Pad" H 6000 2308 50  0000 L CNN
F 2 "MountingHole:MountingHole_2.2mm_M2_ISO7380_Pad" H 5900 2350 50  0001 C CNN
F 3 "~" H 5900 2350 50  0001 C CNN
	1    5900 2350
	1    0    0    -1  
$EndComp
$Comp
L wireless_measurement_ard-rescue:EFM8LB1-MCU_SiliconLabs U1
U 1 1 611E9E7B
P 5100 5900
F 0 "U1" H 5100 6915 50  0000 C CNN
F 1 "EFM8LB1" H 5100 6824 50  0000 C CNN
F 2 "Package_DFN_QFN:QFN-32-1EP_4x4mm_P0.4mm_EP2.9x2.9mm" H 5150 6100 50  0001 C CNN
F 3 "" H 5150 6100 50  0001 C CNN
	1    5100 5900
	1    0    0    -1  
$EndComp
Text GLabel 5700 5450 2    50   Input ~ 0
ARD_TX
Text GLabel 5700 5550 2    50   Input ~ 0
ARD_RX
$Comp
L power:GND #PWR0108
U 1 1 611EDCB4
P 5100 6900
F 0 "#PWR0108" H 5100 6650 50  0001 C CNN
F 1 "GND" H 5105 6727 50  0000 C CNN
F 2 "" H 5100 6900 50  0001 C CNN
F 3 "" H 5100 6900 50  0001 C CNN
	1    5100 6900
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0109
U 1 1 611EE56A
P 4500 5250
F 0 "#PWR0109" H 4500 5100 50  0001 C CNN
F 1 "+3.3V" H 4515 5423 50  0000 C CNN
F 2 "" H 4500 5250 50  0001 C CNN
F 3 "" H 4500 5250 50  0001 C CNN
	1    4500 5250
	0    -1   -1   0   
$EndComp
$Comp
L power:+3.3V #PWR0110
U 1 1 611EF11F
P 4500 5350
F 0 "#PWR0110" H 4500 5200 50  0001 C CNN
F 1 "+3.3V" H 4515 5523 50  0000 C CNN
F 2 "" H 4500 5350 50  0001 C CNN
F 3 "" H 4500 5350 50  0001 C CNN
	1    4500 5350
	0    -1   -1   0   
$EndComp
Text GLabel 4500 5450 0    50   Input ~ 0
C2CK
Text GLabel 4500 5550 0    50   Input ~ 0
C2D
Text GLabel 5700 6050 2    50   Input ~ 0
PWRC
Text GLabel 5700 6150 2    50   Input ~ 0
STATUS
Text GLabel 5700 6250 2    50   Input ~ 0
A3
Text GLabel 5700 6350 2    50   Input ~ 0
A2
Text GLabel 5700 6450 2    50   Input ~ 0
A1
$Comp
L power:GND #PWR0104
U 1 1 61019046
P 6500 3850
F 0 "#PWR0104" H 6500 3600 50  0001 C CNN
F 1 "GND" H 6505 3677 50  0000 C CNN
F 2 "" H 6500 3850 50  0001 C CNN
F 3 "" H 6500 3850 50  0001 C CNN
	1    6500 3850
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R3
U 1 1 6101884F
P 6350 3850
F 0 "R3" V 6450 3800 50  0000 L CNN
F 1 "1k" V 6250 3800 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 6280 3850 50  0001 C CNN
F 3 "~" H 6350 3850 50  0001 C CNN
	1    6350 3850
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D1
U 1 1 61017CC7
P 6050 3850
F 0 "D1" H 6050 3750 50  0000 C CNN
F 1 "LED" H 6050 3950 50  0000 C CNN
F 2 "LED_SMD:LED_0603_1608Metric" H 6050 3850 50  0001 C CNN
F 3 "~" H 6050 3850 50  0001 C CNN
	1    6050 3850
	-1   0    0    1   
$EndComp
Text GLabel 5900 3850 0    50   Input ~ 0
LED
Text GLabel 3650 4800 2    50   Input ~ 0
LED
Text GLabel 5700 5850 2    50   Input ~ 0
LED
Text GLabel 5700 6550 2    50   Input ~ 0
A0
$Comp
L Device:C C7
U 1 1 614EE1A5
P 2350 3950
F 0 "C7" H 2100 4000 50  0000 L CNN
F 1 "4.7uF" H 2050 3900 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.08x0.95mm_HandSolder" H 2388 3800 50  0001 C CNN
F 3 "~" H 2350 3950 50  0001 C CNN
	1    2350 3950
	-1   0    0    1   
$EndComp
Wire Wire Line
	2350 4100 2350 4200
Wire Wire Line
	2350 4200 2300 4200
Wire Wire Line
	2650 4200 2350 4200
Connection ~ 2350 4200
$Comp
L Device:R R6
U 1 1 614F21C7
P 7300 3150
F 0 "R6" V 7400 3100 50  0000 L CNN
F 1 "1k" V 7200 3100 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad0.98x0.95mm_HandSolder" V 7230 3150 50  0001 C CNN
F 3 "~" H 7300 3150 50  0001 C CNN
	1    7300 3150
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0111
U 1 1 614F2925
P 7300 3000
F 0 "#PWR0111" H 7300 2850 50  0001 C CNN
F 1 "+3.3V" H 7315 3173 50  0000 C CNN
F 2 "" H 7300 3000 50  0001 C CNN
F 3 "" H 7300 3000 50  0001 C CNN
	1    7300 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	7150 3300 7300 3300
Connection ~ 7300 3300
Wire Wire Line
	7300 3300 7450 3300
Text GLabel 3650 4900 2    50   Input ~ 0
P1.1
Text GLabel 3650 4700 2    50   Input ~ 0
P0.7
Text GLabel 3650 4600 2    50   Input ~ 0
P0.6
Text GLabel 3650 4300 2    50   Input ~ 0
P0.3
Text GLabel 3650 4100 2    50   Input ~ 0
P0.1
Text GLabel 3650 4200 2    50   Input ~ 0
P0.2
Text GLabel 3650 5600 2    50   Input ~ 0
P2.0
Text GLabel 2650 5600 0    50   Input ~ 0
P2.1
Text GLabel 2650 5500 0    50   Input ~ 0
P2.2
Text GLabel 2650 5400 0    50   Input ~ 0
P2.3
Text GLabel 2650 5300 0    50   Input ~ 0
P2.4
Text GLabel 2650 5200 0    50   Input ~ 0
P2.5
Text GLabel 2650 5100 0    50   Input ~ 0
P2.6
Text GLabel 2650 5000 0    50   Input ~ 0
P3.0
Text GLabel 2650 4900 0    50   Input ~ 0
P3.1
Text GLabel 2650 4800 0    50   Input ~ 0
P3.2
Text GLabel 2650 4700 0    50   Input ~ 0
P3.3
Text GLabel 2650 4100 0    50   Input ~ 0
P0.0
Text GLabel 2350 3800 0    50   Input ~ 0
P0.0
Text GLabel 4500 6650 0    50   Input ~ 0
P2.1
Text GLabel 4500 6550 0    50   Input ~ 0
P2.2
Text GLabel 4500 6450 0    50   Input ~ 0
P2.3
Text GLabel 4500 6350 0    50   Input ~ 0
P2.4
Text GLabel 4500 6250 0    50   Input ~ 0
P2.5
Text GLabel 4500 6150 0    50   Input ~ 0
P2.6
Text GLabel 4500 6050 0    50   Input ~ 0
P3.0
Text GLabel 4500 5950 0    50   Input ~ 0
P3.1
Text GLabel 4500 5850 0    50   Input ~ 0
P3.2
Text GLabel 4500 5750 0    50   Input ~ 0
P3.3
Text GLabel 5700 5650 2    50   Input ~ 0
P0.6
Text GLabel 5700 5750 2    50   Input ~ 0
P0.7
Text GLabel 5700 5950 2    50   Input ~ 0
P1.1
Text GLabel 5700 6650 2    50   Input ~ 0
P2.0
Text GLabel 5700 5350 2    50   Input ~ 0
P0.3
Text GLabel 5700 5150 2    50   Input ~ 0
P0.1
Text GLabel 5700 5250 2    50   Input ~ 0
P0.2
Text GLabel 4500 5150 0    50   Input ~ 0
P0.0
$Comp
L ben_common:MAX44284 U4
U 1 1 61508E2E
P 8800 1650
F 0 "U4" H 8800 1975 50  0000 C CNN
F 1 "MAX44284" H 8800 1884 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23-6_Handsoldering" H 8800 1450 50  0001 C CNN
F 3 "https://datasheets.maximintegrated.com/en/ds/MAX44284.pdf" H 8800 1450 50  0001 C CNN
	1    8800 1650
	1    0    0    -1  
$EndComp
Text GLabel 9150 1550 2    50   Input ~ 0
A0
$Comp
L power:GND #PWR0101
U 1 1 61509478
P 8300 1750
F 0 "#PWR0101" H 8300 1500 50  0001 C CNN
F 1 "GND" H 8305 1577 50  0000 C CNN
F 2 "" H 8300 1750 50  0001 C CNN
F 3 "" H 8300 1750 50  0001 C CNN
	1    8300 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	8450 1750 8300 1750
$Comp
L power:+3.3V #PWR0122
U 1 1 6150FCA8
P 8200 1650
F 0 "#PWR0122" H 8200 1500 50  0001 C CNN
F 1 "+3.3V" H 8215 1823 50  0000 C CNN
F 2 "" H 8200 1650 50  0001 C CNN
F 3 "" H 8200 1650 50  0001 C CNN
	1    8200 1650
	0    -1   -1   0   
$EndComp
Wire Wire Line
	8200 1650 8400 1650
$Comp
L Device:R R2
U 1 1 615123F2
P 9450 1700
F 0 "R2" H 9520 1746 50  0000 L CNN
F 1 "1R" H 9520 1655 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" V 9380 1700 50  0001 C CNN
F 3 "~" H 9450 1700 50  0001 C CNN
	1    9450 1700
	1    0    0    -1  
$EndComp
Text GLabel 9800 1650 2    50   Input ~ 0
C1_OUT
Wire Wire Line
	9650 1650 9800 1650
Wire Wire Line
	9650 1750 9800 1750
Text GLabel 9800 1750 2    50   Input ~ 0
C1_IN
Wire Wire Line
	9650 1650 9650 1550
Wire Wire Line
	9650 1850 9650 1750
Wire Wire Line
	9650 1550 9450 1550
Wire Wire Line
	9450 1550 9350 1550
Wire Wire Line
	9350 1550 9350 1650
Wire Wire Line
	9350 1650 9150 1650
Connection ~ 9450 1550
Wire Wire Line
	9150 1750 9350 1750
Wire Wire Line
	9350 1750 9350 1850
Wire Wire Line
	9350 1850 9450 1850
Connection ~ 9450 1850
Wire Wire Line
	9450 1850 9650 1850
Wire Wire Line
	8450 1550 8400 1550
Wire Wire Line
	8400 1550 8400 1650
Connection ~ 8400 1650
Wire Wire Line
	8400 1650 8450 1650
$EndSCHEMATC
