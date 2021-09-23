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
F 2 "ben_common:JDY-08_HandSoldering" H 5000 2000 60  0001 C CNN
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
$Comp
L power:GND #PWR0101
U 1 1 60F7603A
P 8550 1850
F 0 "#PWR0101" H 8550 1600 50  0001 C CNN
F 1 "GND" H 8555 1677 50  0000 C CNN
F 2 "" H 8550 1850 50  0001 C CNN
F 3 "" H 8550 1850 50  0001 C CNN
	1    8550 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	8550 1650 8400 1650
Text GLabel 9350 1450 2    50   Input ~ 0
A0
Text GLabel 9300 3000 0    50   Input ~ 0
A1
Wire Wire Line
	9250 1650 9350 1650
Wire Wire Line
	9350 1650 9350 1550
Wire Wire Line
	9250 1750 9350 1750
Wire Wire Line
	9350 1750 9350 1850
Connection ~ 9450 1550
Connection ~ 9450 1850
Wire Wire Line
	9450 1850 9650 1850
Wire Wire Line
	9350 1850 9450 1850
Wire Wire Line
	9450 1550 9650 1550
Wire Wire Line
	9350 1550 9450 1550
$Comp
L Device:R R1
U 1 1 60F77736
P 9450 1700
F 0 "R1" H 9520 1746 50  0000 L CNN
F 1 "1R" H 9520 1655 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 9380 1700 50  0001 C CNN
F 3 "~" H 9450 1700 50  0001 C CNN
	1    9450 1700
	1    0    0    -1  
$EndComp
Wire Wire Line
	9650 1850 9650 1750
Wire Wire Line
	9650 1650 9650 1550
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
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x04_P2.54mm_Vertical" H 9500 3100 50  0001 C CNN
F 3 "~" H 9500 3100 50  0001 C CNN
	1    9500 3100
	1    0    0    -1  
$EndComp
Text GLabel 9300 3100 0    50   Input ~ 0
VHIGH
$Comp
L power:GND #PWR0106
U 1 1 60F9306D
P 9100 3500
F 0 "#PWR0106" H 9100 3250 50  0001 C CNN
F 1 "GND" V 9100 3300 50  0000 C CNN
F 2 "" H 9100 3500 50  0001 C CNN
F 3 "" H 9100 3500 50  0001 C CNN
	1    9100 3500
	0    1    1    0   
$EndComp
Text GLabel 9800 1750 2    50   Input ~ 0
C1_IN
Wire Wire Line
	9650 1750 9800 1750
Wire Wire Line
	9650 1650 9800 1650
Text GLabel 9300 2800 0    50   Input ~ 0
C1_IN
Text GLabel 9800 1650 2    50   Input ~ 0
C1_OUT
Text GLabel 9300 2900 0    50   Input ~ 0
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
Wire Wire Line
	8550 1750 8550 1850
$Comp
L power:+3.3V #PWR0118
U 1 1 6100B7A7
P 4850 4550
F 0 "#PWR0118" H 4850 4400 50  0001 C CNN
F 1 "+3.3V" H 4865 4723 50  0000 C CNN
F 2 "" H 4850 4550 50  0001 C CNN
F 3 "" H 4850 4550 50  0001 C CNN
	1    4850 4550
	1    0    0    -1  
$EndComp
$Comp
L Device:C C6
U 1 1 610112E3
P 5100 4800
F 0 "C6" H 5150 4900 50  0000 L CNN
F 1 "0.1uF" H 5150 4700 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 5138 4650 50  0001 C CNN
F 3 "~" H 5100 4800 50  0001 C CNN
	1    5100 4800
	1    0    0    -1  
$EndComp
$Comp
L Device:C C5
U 1 1 61011D4D
P 4850 4800
F 0 "C5" H 4600 4850 50  0000 L CNN
F 1 "4.7uF" H 4550 4750 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 4888 4650 50  0001 C CNN
F 3 "~" H 4850 4800 50  0001 C CNN
	1    4850 4800
	1    0    0    -1  
$EndComp
Wire Wire Line
	4850 4650 4850 4550
Wire Wire Line
	5100 4650 4850 4650
$Comp
L power:GND #PWR0119
U 1 1 61016AAB
P 5000 4950
F 0 "#PWR0119" H 5000 4700 50  0001 C CNN
F 1 "GND" H 5005 4777 50  0000 C CNN
F 2 "" H 5000 4950 50  0001 C CNN
F 3 "" H 5000 4950 50  0001 C CNN
	1    5000 4950
	1    0    0    -1  
$EndComp
Wire Wire Line
	4850 4950 5000 4950
Connection ~ 5000 4950
Wire Wire Line
	5000 4950 5100 4950
Text GLabel 3850 1300 2    50   Input ~ 0
STATUS
Connection ~ 4850 4650
Wire Wire Line
	8550 4450 8950 4450
$Comp
L Switch:SW_SPDT SW1
U 1 1 61043960
P 10500 3450
F 0 "SW1" H 10500 3735 50  0000 C CNN
F 1 "SW_SPDT" H 10500 3644 50  0000 C CNN
F 2 "ben_common:SW_SPDT_CK-JS102011SAQN" H 10500 3450 50  0001 C CNN
F 3 "~" H 10500 3450 50  0001 C CNN
	1    10500 3450
	1    0    0    -1  
$EndComp
Text GLabel 10700 3350 2    50   Input ~ 0
BATT
Text GLabel 10300 3450 0    50   Input ~ 0
VIN
$Comp
L wireless_measurement_ard-rescue:EFM8LB1-MCU_SiliconLabs-wireless_measurement_ard-rescue U1
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
Text GLabel 6450 2350 2    50   Input ~ 0
A3
Text GLabel 6450 2450 2    50   Input ~ 0
A2
Text GLabel 6450 2550 2    50   Input ~ 0
A1
$Comp
L power:GND #PWR0104
U 1 1 61019046
P 6450 4800
F 0 "#PWR0104" H 6450 4550 50  0001 C CNN
F 1 "GND" H 6455 4627 50  0000 C CNN
F 2 "" H 6450 4800 50  0001 C CNN
F 3 "" H 6450 4800 50  0001 C CNN
	1    6450 4800
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R3
U 1 1 6101884F
P 6300 4800
F 0 "R3" V 6400 4750 50  0000 L CNN
F 1 "1k" V 6200 4750 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad0.98x0.95mm_HandSolder" V 6230 4800 50  0001 C CNN
F 3 "~" H 6300 4800 50  0001 C CNN
	1    6300 4800
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D1
U 1 1 61017CC7
P 6000 4800
F 0 "D1" H 6000 4700 50  0000 C CNN
F 1 "LED" H 6000 4900 50  0000 C CNN
F 2 "LED_SMD:LED_0603_1608Metric" H 6000 4800 50  0001 C CNN
F 3 "~" H 6000 4800 50  0001 C CNN
	1    6000 4800
	-1   0    0    1   
$EndComp
Text GLabel 5850 4800 0    50   Input ~ 0
LED
Text GLabel 6450 1950 2    50   Input ~ 0
LED
Text GLabel 6450 2650 2    50   Input ~ 0
A0
$Comp
L Device:R R6
U 1 1 6128E69D
P 4900 1400
F 0 "R6" V 5000 1350 50  0000 L CNN
F 1 "1k" V 4800 1350 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad0.98x0.95mm_HandSolder" V 4830 1400 50  0001 C CNN
F 3 "~" H 4900 1400 50  0001 C CNN
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
Wire Wire Line
	9100 3500 9300 3500
$Comp
L Device:R R7
U 1 1 6131256B
P 7350 3200
F 0 "R7" V 7450 3150 50  0000 L CNN
F 1 "110k" V 7250 3150 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad0.98x0.95mm_HandSolder" V 7280 3200 50  0001 C CNN
F 3 "~" H 7350 3200 50  0001 C CNN
	1    7350 3200
	1    0    0    -1  
$EndComp
$Comp
L Device:R R8
U 1 1 61316095
P 7350 3600
F 0 "R8" V 7450 3550 50  0000 L CNN
F 1 "10k" V 7250 3550 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad0.98x0.95mm_HandSolder" V 7280 3600 50  0001 C CNN
F 3 "~" H 7350 3600 50  0001 C CNN
	1    7350 3600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0110
U 1 1 613169FE
P 7350 3750
F 0 "#PWR0110" H 7350 3500 50  0001 C CNN
F 1 "GND" H 7355 3577 50  0000 C CNN
F 2 "" H 7350 3750 50  0001 C CNN
F 3 "" H 7350 3750 50  0001 C CNN
	1    7350 3750
	1    0    0    -1  
$EndComp
Text GLabel 7350 3050 1    50   Input ~ 0
VHIGH
Wire Wire Line
	7350 3350 7350 3450
Text GLabel 7000 3450 0    50   Input ~ 0
A3
Wire Wire Line
	7350 3450 7000 3450
Connection ~ 7350 3450
$Comp
L wireless_measurement_ard-rescue:MAX44284 U4
U 1 1 612DBC77
P 8900 1650
F 0 "U4" H 8900 1975 50  0000 C CNN
F 1 "MAX44284" H 8900 1884 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23-6_Handsoldering" H 8900 1450 50  0001 C CNN
F 3 "https://datasheets.maximintegrated.com/en/ds/MAX44284.pdf" H 8900 1450 50  0001 C CNN
	1    8900 1650
	1    0    0    -1  
$EndComp
Wire Wire Line
	9250 1550 9250 1450
Wire Wire Line
	9250 1450 9350 1450
Wire Wire Line
	8550 1550 8400 1550
Wire Wire Line
	8400 1550 8400 1650
$Comp
L power:+3.3V #PWR0111
U 1 1 612E1F0B
P 8400 1550
F 0 "#PWR0111" H 8400 1400 50  0001 C CNN
F 1 "+3.3V" H 8415 1723 50  0000 C CNN
F 2 "" H 8400 1550 50  0001 C CNN
F 3 "" H 8400 1550 50  0001 C CNN
	1    8400 1550
	1    0    0    -1  
$EndComp
Connection ~ 8400 1550
Text GLabel 6450 1850 2    50   Input ~ 0
A4
Text GLabel 9300 3400 0    50   Input ~ 0
BATT
Text GLabel 9300 3200 0    50   Input ~ 0
C2CK
Text GLabel 9300 3300 0    50   Input ~ 0
C2D
$Comp
L Device:C C7
U 1 1 613D1737
P 5250 1100
F 0 "C7" H 5000 1150 50  0000 L CNN
F 1 "4.7uF" H 4950 1050 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.08x0.95mm_HandSolder" H 5288 950 50  0001 C CNN
F 3 "~" H 5250 1100 50  0001 C CNN
	1    5250 1100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 613D2357
P 5250 950
F 0 "#PWR0102" H 5250 700 50  0001 C CNN
F 1 "GND" H 5255 777 50  0000 C CNN
F 2 "" H 5250 950 50  0001 C CNN
F 3 "" H 5250 950 50  0001 C CNN
	1    5250 950 
	0    -1   -1   0   
$EndComp
Text GLabel 6450 1750 2    50   Input ~ 0
HALL_PIN
$Comp
L ben_common:DRV5021 U5
U 1 1 6148F942
P 7400 1750
F 0 "U5" H 7400 2025 50  0000 C CNN
F 1 "DRV5021" H 7400 1950 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 7100 1950 50  0001 C CNN
F 3 "" H 7100 1950 50  0001 C CNN
	1    7400 1750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0105
U 1 1 6149026D
P 7700 2100
F 0 "#PWR0105" H 7700 1850 50  0001 C CNN
F 1 "GND" H 7705 1927 50  0000 C CNN
F 2 "" H 7700 2100 50  0001 C CNN
F 3 "" H 7700 2100 50  0001 C CNN
	1    7700 2100
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0117
U 1 1 61490741
P 7100 1750
F 0 "#PWR0117" H 7100 1600 50  0001 C CNN
F 1 "+3.3V" H 7115 1923 50  0000 C CNN
F 2 "" H 7100 1750 50  0001 C CNN
F 3 "" H 7100 1750 50  0001 C CNN
	1    7100 1750
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0120
U 1 1 61490CF5
P 7800 1400
F 0 "#PWR0120" H 7800 1250 50  0001 C CNN
F 1 "+3.3V" H 7815 1573 50  0000 C CNN
F 2 "" H 7800 1400 50  0001 C CNN
F 3 "" H 7800 1400 50  0001 C CNN
	1    7800 1400
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 614912CF
P 7800 1550
F 0 "R2" H 7870 1596 50  0000 L CNN
F 1 "10k" H 7870 1505 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad0.98x0.95mm_HandSolder" V 7730 1550 50  0001 C CNN
F 3 "~" H 7800 1550 50  0001 C CNN
	1    7800 1550
	1    0    0    -1  
$EndComp
Wire Wire Line
	7700 1700 7800 1700
Text GLabel 8000 1700 2    50   Input ~ 0
HALL_PIN
Wire Wire Line
	7800 1700 8000 1700
Connection ~ 7800 1700
$Comp
L Device:C C8
U 1 1 6149AFDF
P 7100 1900
F 0 "C8" H 6850 1950 50  0000 L CNN
F 1 "0.1uF" H 6800 1850 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.08x0.95mm_HandSolder" H 7138 1750 50  0001 C CNN
F 3 "~" H 7100 1900 50  0001 C CNN
	1    7100 1900
	1    0    0    -1  
$EndComp
Connection ~ 7100 1750
Wire Wire Line
	7100 2050 7700 2050
Wire Wire Line
	7700 2050 7700 2100
Wire Wire Line
	7700 1850 7700 2050
Connection ~ 7700 2050
$EndSCHEMATC