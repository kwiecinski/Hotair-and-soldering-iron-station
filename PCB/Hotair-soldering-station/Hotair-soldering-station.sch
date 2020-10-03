EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A2 23386 16535
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
L Transistor_BJT:TIP122 Q?
U 1 1 5F775EA9
P 3750 6400
F 0 "Q?" V 4094 6400 50  0000 C CNN
F 1 "TIP122" V 4003 6400 50  0000 C CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 3950 6325 50  0001 L CIN
F 3 "http://www.fairchildsemi.com/ds/TI/TIP120.pdf" H 3750 6400 50  0001 L CNN
	1    3750 6400
	0    -1   -1   0   
$EndComp
$Comp
L Transistor_BJT:BC817 Q?
U 1 1 5F777E6C
P 3850 7200
F 0 "Q?" H 4041 7246 50  0000 L CNN
F 1 "BC817" H 4041 7155 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 4050 7125 50  0001 L CIN
F 3 "http://www.fairchildsemi.com/ds/BC/BC817.pdf" H 3850 7200 50  0001 L CNN
	1    3850 7200
	-1   0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5F77A712
P 3300 6600
F 0 "R?" H 3230 6554 50  0000 R CNN
F 1 "5k1" H 3230 6645 50  0000 R CNN
F 2 "Capacitors:0805" V 3230 6600 50  0001 C CNN
F 3 "~" H 3300 6600 50  0001 C CNN
	1    3300 6600
	-1   0    0    1   
$EndComp
$Comp
L Device:R R?
U 1 1 5F77B6A1
P 2850 6600
F 0 "R?" H 2780 6554 50  0000 R CNN
F 1 "5k1" H 2780 6645 50  0000 R CNN
F 2 "Capacitors:0805" V 2780 6600 50  0001 C CNN
F 3 "~" H 2850 6600 50  0001 C CNN
	1    2850 6600
	-1   0    0    1   
$EndComp
Wire Wire Line
	2200 6300 2200 6050
Wire Wire Line
	2850 6450 2850 6300
Connection ~ 2850 6300
Wire Wire Line
	2850 6300 2200 6300
$Comp
L Device:D_Zener D?
U 1 1 5F77C801
P 2850 7350
F 0 "D?" V 2804 7429 50  0000 L CNN
F 1 "8V2" V 2895 7429 50  0000 L CNN
F 2 "Diode_THT:D_DO-34_SOD68_P7.62mm_Horizontal" H 2850 7350 50  0001 C CNN
F 3 "~" H 2850 7350 50  0001 C CNN
	1    2850 7350
	0    1    1    0   
$EndComp
Wire Wire Line
	2850 7200 2850 7150
Wire Wire Line
	3750 7400 3750 7500
Wire Wire Line
	3750 7500 3250 7500
Wire Wire Line
	3250 7500 3250 7150
Wire Wire Line
	3250 7150 2850 7150
Connection ~ 2850 7150
Wire Wire Line
	2850 7150 2850 6750
$Comp
L power:GND #PWR?
U 1 1 5F77DB18
P 2850 7650
F 0 "#PWR?" H 2850 7400 50  0001 C CNN
F 1 "GND" H 2855 7477 50  0000 C CNN
F 2 "" H 2850 7650 50  0001 C CNN
F 3 "" H 2850 7650 50  0001 C CNN
	1    2850 7650
	1    0    0    -1  
$EndComp
$Comp
L Transistor_BJT:BC817 Q?
U 1 1 5F77E614
P 2200 7150
F 0 "Q?" H 2391 7196 50  0000 L CNN
F 1 "BC817" H 2391 7105 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 2400 7075 50  0001 L CIN
F 3 "http://www.fairchildsemi.com/ds/BC/BC817.pdf" H 2200 7150 50  0001 L CNN
	1    2200 7150
	1    0    0    -1  
$EndComp
Wire Wire Line
	2850 7650 2850 7500
$Comp
L power:GND #PWR?
U 1 1 5F7864B2
P 2300 7650
F 0 "#PWR?" H 2300 7400 50  0001 C CNN
F 1 "GND" H 2305 7477 50  0000 C CNN
F 2 "" H 2300 7650 50  0001 C CNN
F 3 "" H 2300 7650 50  0001 C CNN
	1    2300 7650
	1    0    0    -1  
$EndComp
Wire Wire Line
	2300 6950 2300 6900
Wire Wire Line
	2300 6900 3300 6900
Connection ~ 3750 6900
Wire Wire Line
	3750 6900 3750 7000
Wire Wire Line
	2300 7650 2300 7350
Wire Wire Line
	1800 7150 2000 7150
$Comp
L Device:R R?
U 1 1 5F788586
P 1650 7150
F 0 "R?" V 1857 7150 50  0000 C CNN
F 1 "R" V 1766 7150 50  0000 C CNN
F 2 "" V 1580 7150 50  0001 C CNN
F 3 "~" H 1650 7150 50  0001 C CNN
	1    1650 7150
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R?
U 1 1 5F78ADB6
P 4500 6600
F 0 "R?" H 4430 6554 50  0000 R CNN
F 1 "5k6" H 4430 6645 50  0000 R CNN
F 2 "Capacitors:0805" V 4430 6600 50  0001 C CNN
F 3 "~" H 4500 6600 50  0001 C CNN
	1    4500 6600
	-1   0    0    1   
$EndComp
Wire Wire Line
	3950 6300 4500 6300
Wire Wire Line
	4500 6300 4500 6450
$Comp
L Device:R R?
U 1 1 5F78B92D
P 4500 7350
F 0 "R?" H 4430 7304 50  0000 R CNN
F 1 "7k5" H 4430 7395 50  0000 R CNN
F 2 "Capacitors:0805" V 4430 7350 50  0001 C CNN
F 3 "~" H 4500 7350 50  0001 C CNN
	1    4500 7350
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F78C6B5
P 4500 7650
F 0 "#PWR?" H 4500 7400 50  0001 C CNN
F 1 "GND" H 4505 7477 50  0000 C CNN
F 2 "" H 4500 7650 50  0001 C CNN
F 3 "" H 4500 7650 50  0001 C CNN
	1    4500 7650
	1    0    0    -1  
$EndComp
Wire Wire Line
	4500 7650 4500 7500
Wire Wire Line
	4500 6300 5050 6300
Connection ~ 4500 6300
$Comp
L Device:R_POT RV?
U 1 1 5F78D931
P 4500 6950
F 0 "RV?" H 4430 6904 50  0000 R CNN
F 1 "R_POT" H 4430 6995 50  0000 R CNN
F 2 "" H 4500 6950 50  0001 C CNN
F 3 "~" H 4500 6950 50  0001 C CNN
	1    4500 6950
	-1   0    0    1   
$EndComp
Wire Wire Line
	4500 6800 4500 6750
Wire Wire Line
	4500 7200 4500 7100
Wire Wire Line
	4350 6950 4200 6950
Wire Wire Line
	4200 6950 4200 7200
Wire Wire Line
	4200 7200 4050 7200
Wire Wire Line
	3750 6600 3750 6900
Wire Wire Line
	2850 6300 3300 6300
Wire Wire Line
	3300 6750 3300 6900
Connection ~ 3300 6900
Wire Wire Line
	3300 6900 3750 6900
Wire Wire Line
	3300 6450 3300 6300
Connection ~ 3300 6300
Wire Wire Line
	3300 6300 3550 6300
Wire Wire Line
	1500 7150 1300 7150
$Comp
L power:+24V #PWR?
U 1 1 5F798EA8
P 2200 6050
F 0 "#PWR?" H 2200 5900 50  0001 C CNN
F 1 "+24V" H 2215 6223 50  0000 C CNN
F 2 "" H 2200 6050 50  0001 C CNN
F 3 "" H 2200 6050 50  0001 C CNN
	1    2200 6050
	1    0    0    -1  
$EndComp
Text GLabel 1300 7150 0    50   Input ~ 0
FAN_EN
Text GLabel 5050 6300 2    50   Input ~ 0
FAN_SUPPLY
Wire Notes Line
	700  8800 6000 8800
Wire Notes Line
	6000 8800 6000 5500
Wire Notes Line
	6000 5500 700  5500
Wire Notes Line
	700  5500 700  8800
$Comp
L Switch:SW_Push SW?
U 1 1 5F7B7AE4
P 18950 1850
F 0 "SW?" H 18950 2135 50  0000 C CNN
F 1 "SW_Push" H 18950 2044 50  0000 C CNN
F 2 "" H 18950 2050 50  0001 C CNN
F 3 "~" H 18950 2050 50  0001 C CNN
	1    18950 1850
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW?
U 1 1 5F7B8E75
P 18950 2050
F 0 "SW?" H 18950 2335 50  0000 C CNN
F 1 "SW_Push" H 18950 2244 50  0000 C CNN
F 2 "" H 18950 2250 50  0001 C CNN
F 3 "~" H 18950 2250 50  0001 C CNN
	1    18950 2050
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW?
U 1 1 5F7BA8A4
P 19000 3250
F 0 "SW?" H 19000 3535 50  0000 C CNN
F 1 "SW_Push" H 19000 3444 50  0000 C CNN
F 2 "" H 19000 3450 50  0001 C CNN
F 3 "~" H 19000 3450 50  0001 C CNN
	1    19000 3250
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW?
U 1 1 5F7BA8AA
P 19000 3450
F 0 "SW?" H 19000 3735 50  0000 C CNN
F 1 "SW_Push" H 19000 3644 50  0000 C CNN
F 2 "" H 19000 3650 50  0001 C CNN
F 3 "~" H 19000 3650 50  0001 C CNN
	1    19000 3450
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F7BD11A
P 18700 3650
F 0 "#PWR?" H 18700 3400 50  0001 C CNN
F 1 "GND" H 18705 3477 50  0000 C CNN
F 2 "" H 18700 3650 50  0001 C CNN
F 3 "" H 18700 3650 50  0001 C CNN
	1    18700 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	18800 3450 18700 3450
Wire Wire Line
	18700 3450 18700 3650
Wire Wire Line
	18800 3250 18700 3250
Wire Wire Line
	18700 3250 18700 3450
Connection ~ 18700 3450
Wire Wire Line
	18750 2050 18650 2050
Wire Wire Line
	18750 1850 18650 1850
Wire Wire Line
	18650 1850 18650 2050
$Comp
L Connector_Generic:Conn_01x02 J?
U 1 1 5F7C04E4
P 20800 3300
F 0 "J?" H 20718 2975 50  0000 C CNN
F 1 "Conn_01x02" H 20718 3066 50  0000 C CNN
F 2 "" H 20800 3300 50  0001 C CNN
F 3 "~" H 20800 3300 50  0001 C CNN
	1    20800 3300
	-1   0    0    1   
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J?
U 1 1 5F7C1591
P 20800 1950
F 0 "J?" H 20718 1625 50  0000 C CNN
F 1 "Conn_01x02" H 20718 1716 50  0000 C CNN
F 2 "" H 20800 1950 50  0001 C CNN
F 3 "~" H 20800 1950 50  0001 C CNN
	1    20800 1950
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F7C6EA1
P 21000 2150
F 0 "#PWR?" H 21000 1900 50  0001 C CNN
F 1 "GND" H 21005 1977 50  0000 C CNN
F 2 "" H 21000 2150 50  0001 C CNN
F 3 "" H 21000 2150 50  0001 C CNN
	1    21000 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	21000 2150 21000 1950
$Comp
L power:GND #PWR?
U 1 1 5F7C8070
P 21000 3550
F 0 "#PWR?" H 21000 3300 50  0001 C CNN
F 1 "GND" H 21005 3377 50  0000 C CNN
F 2 "" H 21000 3550 50  0001 C CNN
F 3 "" H 21000 3550 50  0001 C CNN
	1    21000 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	21000 3550 21000 3300
$Comp
L Device:R R?
U 1 1 5F7C9253
P 19250 1550
F 0 "R?" H 19180 1504 50  0000 R CNN
F 1 "5k6" H 19180 1595 50  0000 R CNN
F 2 "Capacitors:0805" V 19180 1550 50  0001 C CNN
F 3 "~" H 19250 1550 50  0001 C CNN
	1    19250 1550
	-1   0    0    1   
$EndComp
$Comp
L Device:R R?
U 1 1 5F7CA1AB
P 19450 1550
F 0 "R?" H 19380 1504 50  0000 R CNN
F 1 "5k6" H 19380 1595 50  0000 R CNN
F 2 "Capacitors:0805" V 19380 1550 50  0001 C CNN
F 3 "~" H 19450 1550 50  0001 C CNN
	1    19450 1550
	-1   0    0    1   
$EndComp
$Comp
L Device:R R?
U 1 1 5F7CA50F
P 19250 3000
F 0 "R?" H 19180 2954 50  0000 R CNN
F 1 "5k6" H 19180 3045 50  0000 R CNN
F 2 "Capacitors:0805" V 19180 3000 50  0001 C CNN
F 3 "~" H 19250 3000 50  0001 C CNN
	1    19250 3000
	-1   0    0    1   
$EndComp
$Comp
L Device:R R?
U 1 1 5F7CB1DD
P 19450 3000
F 0 "R?" H 19380 2954 50  0000 R CNN
F 1 "5k6" H 19380 3045 50  0000 R CNN
F 2 "Capacitors:0805" V 19380 3000 50  0001 C CNN
F 3 "~" H 19450 3000 50  0001 C CNN
	1    19450 3000
	-1   0    0    1   
$EndComp
$Comp
L Device:R R?
U 1 1 5F7CB509
P 21200 1550
F 0 "R?" H 21130 1504 50  0000 R CNN
F 1 "5k6" H 21130 1595 50  0000 R CNN
F 2 "Capacitors:0805" V 21130 1550 50  0001 C CNN
F 3 "~" H 21200 1550 50  0001 C CNN
	1    21200 1550
	-1   0    0    1   
$EndComp
$Comp
L Device:R R?
U 1 1 5F7CBF5F
P 21200 2950
F 0 "R?" H 21130 2904 50  0000 R CNN
F 1 "5k6" H 21130 2995 50  0000 R CNN
F 2 "Capacitors:0805" V 21130 2950 50  0001 C CNN
F 3 "~" H 21200 2950 50  0001 C CNN
	1    21200 2950
	-1   0    0    1   
$EndComp
Wire Wire Line
	21000 3200 21200 3200
Wire Wire Line
	21200 3200 21200 3100
Wire Wire Line
	21200 3200 21500 3200
Connection ~ 21200 3200
Wire Wire Line
	21000 1850 21200 1850
Wire Wire Line
	21200 1850 21200 1700
Wire Wire Line
	19250 1350 19250 1400
Wire Wire Line
	19450 1400 19450 1350
Wire Wire Line
	19450 1350 19350 1350
Wire Wire Line
	19150 1850 19250 1850
Wire Wire Line
	19250 1850 19250 1700
Wire Wire Line
	19150 2050 19450 2050
Wire Wire Line
	19450 2050 19450 1700
Wire Wire Line
	19250 1850 19700 1850
Connection ~ 19250 1850
Wire Wire Line
	19450 2050 19700 2050
Connection ~ 19450 2050
$Comp
L power:GND #PWR?
U 1 1 5F7D492B
P 18650 2200
F 0 "#PWR?" H 18650 1950 50  0001 C CNN
F 1 "GND" H 18655 2027 50  0000 C CNN
F 2 "" H 18650 2200 50  0001 C CNN
F 3 "" H 18650 2200 50  0001 C CNN
	1    18650 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	18650 2200 18650 2050
Connection ~ 18650 2050
Text GLabel 19700 1850 2    50   Input ~ 0
HOTAIR_UP_SW
Text GLabel 19700 2050 2    50   Input ~ 0
HOTAIR_DOWN_SW
Text GLabel 21350 1850 2    50   Input ~ 0
HOTAIR_ON_SW
Wire Wire Line
	21350 1850 21200 1850
Connection ~ 21200 1850
$Comp
L power:+3.3V #PWR?
U 1 1 5F7DE60B
P 19350 1200
F 0 "#PWR?" H 19350 1050 50  0001 C CNN
F 1 "+3.3V" H 19365 1373 50  0000 C CNN
F 2 "" H 19350 1200 50  0001 C CNN
F 3 "" H 19350 1200 50  0001 C CNN
	1    19350 1200
	1    0    0    -1  
$EndComp
Wire Wire Line
	19350 1200 19350 1350
Connection ~ 19350 1350
Wire Wire Line
	19350 1350 19250 1350
$Comp
L power:+3.3V #PWR?
U 1 1 5F7E0178
P 21200 1200
F 0 "#PWR?" H 21200 1050 50  0001 C CNN
F 1 "+3.3V" H 21215 1373 50  0000 C CNN
F 2 "" H 21200 1200 50  0001 C CNN
F 3 "" H 21200 1200 50  0001 C CNN
	1    21200 1200
	1    0    0    -1  
$EndComp
Wire Wire Line
	21200 1200 21200 1400
Wire Wire Line
	19200 3250 19250 3250
Wire Wire Line
	19250 3250 19250 3150
Wire Wire Line
	19200 3450 19450 3450
Wire Wire Line
	19450 3450 19450 3150
$Comp
L power:+3.3V #PWR?
U 1 1 5F7E67B8
P 21200 2700
F 0 "#PWR?" H 21200 2550 50  0001 C CNN
F 1 "+3.3V" H 21215 2873 50  0000 C CNN
F 2 "" H 21200 2700 50  0001 C CNN
F 3 "" H 21200 2700 50  0001 C CNN
	1    21200 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	21200 2800 21200 2700
$Comp
L power:+3.3V #PWR?
U 1 1 5F7E7E04
P 19350 2700
F 0 "#PWR?" H 19350 2550 50  0001 C CNN
F 1 "+3.3V" H 19365 2873 50  0000 C CNN
F 2 "" H 19350 2700 50  0001 C CNN
F 3 "" H 19350 2700 50  0001 C CNN
	1    19350 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	19250 2850 19250 2700
Wire Wire Line
	19250 2700 19350 2700
Wire Wire Line
	19350 2700 19450 2700
Wire Wire Line
	19450 2700 19450 2850
Connection ~ 19350 2700
Text GLabel 19700 3250 2    50   Input ~ 0
SOLDER_UP_SW
Wire Wire Line
	19700 3250 19250 3250
Connection ~ 19250 3250
Text GLabel 19700 3450 2    50   Input ~ 0
SOLDER_DOWN_SW
Wire Wire Line
	19700 3450 19450 3450
Connection ~ 19450 3450
Text GLabel 21500 3200 2    50   Input ~ 0
SOLDER_ON_SW
Wire Notes Line
	18250 4250 22500 4250
Wire Notes Line
	22500 4250 22500 850 
Wire Notes Line
	22500 850  18250 850 
Wire Notes Line
	18250 850  18250 4250
$Comp
L My-Lib:3-dig-7-seg-display-common-anode U?
U 1 1 5F79E7AA
P 19600 9100
F 0 "U?" H 19925 9275 50  0000 C CNN
F 1 "3-dig-7-seg-display-common-anode" H 19925 9184 50  0000 C CNN
F 2 "" H 19600 9100 50  0001 C CNN
F 3 "" H 19600 9100 50  0001 C CNN
	1    19600 9100
	1    0    0    -1  
$EndComp
$Comp
L Transistor_BJT:BC807 Q?
U 1 1 5F7DAE3F
P 21250 6750
F 0 "Q?" V 21578 6750 50  0000 C CNN
F 1 "BC807" V 21487 6750 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 21450 6675 50  0001 L CIN
F 3 "http://www.fairchildsemi.com/ds/BC/BC807.pdf" H 21250 6750 50  0001 L CNN
	1    21250 6750
	0    -1   -1   0   
$EndComp
$Comp
L Transistor_BJT:BC807 Q?
U 1 1 5F7E04CF
P 21250 7400
F 0 "Q?" V 21578 7400 50  0000 C CNN
F 1 "BC807" V 21487 7400 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 21450 7325 50  0001 L CIN
F 3 "http://www.fairchildsemi.com/ds/BC/BC807.pdf" H 21250 7400 50  0001 L CNN
	1    21250 7400
	0    -1   -1   0   
$EndComp
$Comp
L Transistor_BJT:BC807 Q?
U 1 1 5F7E0DDB
P 21250 8100
F 0 "Q?" V 21578 8100 50  0000 C CNN
F 1 "BC807" V 21487 8100 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 21450 8025 50  0001 L CIN
F 3 "http://www.fairchildsemi.com/ds/BC/BC807.pdf" H 21250 8100 50  0001 L CNN
	1    21250 8100
	0    -1   -1   0   
$EndComp
Wire Wire Line
	21050 7300 21000 7300
Wire Wire Line
	21000 7300 21000 6750
Wire Wire Line
	21450 8000 21550 8000
Wire Wire Line
	21550 8000 21550 7300
Wire Wire Line
	21450 6650 21550 6650
Connection ~ 21550 6650
Wire Wire Line
	21550 6650 21550 6450
Wire Wire Line
	21450 7300 21550 7300
Connection ~ 21550 7300
Wire Wire Line
	21550 7300 21550 6650
$Comp
L power:+3.3V #PWR?
U 1 1 5F7FF0D7
P 21550 6450
F 0 "#PWR?" H 21550 6300 50  0001 C CNN
F 1 "+3.3V" H 21565 6623 50  0000 C CNN
F 2 "" H 21550 6450 50  0001 C CNN
F 3 "" H 21550 6450 50  0001 C CNN
	1    21550 6450
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5F7FFAC4
P 21850 8300
F 0 "R?" H 21780 8254 50  0000 R CNN
F 1 "5k6" H 21780 8345 50  0000 R CNN
F 2 "Capacitors:0805" V 21780 8300 50  0001 C CNN
F 3 "~" H 21850 8300 50  0001 C CNN
	1    21850 8300
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R?
U 1 1 5F8015CB
P 21850 7600
F 0 "R?" H 21780 7554 50  0000 R CNN
F 1 "5k6" H 21780 7645 50  0000 R CNN
F 2 "Capacitors:0805" V 21780 7600 50  0001 C CNN
F 3 "~" H 21850 7600 50  0001 C CNN
	1    21850 7600
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R?
U 1 1 5F801C4F
P 21900 6950
F 0 "R?" H 21830 6904 50  0000 R CNN
F 1 "5k6" H 21830 6995 50  0000 R CNN
F 2 "Capacitors:0805" V 21830 6950 50  0001 C CNN
F 3 "~" H 21900 6950 50  0001 C CNN
	1    21900 6950
	0    -1   -1   0   
$EndComp
Wire Wire Line
	21250 6950 21750 6950
Wire Wire Line
	21250 7600 21700 7600
Wire Wire Line
	21250 8300 21700 8300
Wire Wire Line
	20900 6850 20900 8000
Wire Wire Line
	20900 8000 21050 8000
$Comp
L Transistor_BJT:BC807 Q?
U 1 1 5F831349
P 21250 9250
F 0 "Q?" V 21578 9250 50  0000 C CNN
F 1 "BC807" V 21487 9250 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 21450 9175 50  0001 L CIN
F 3 "http://www.fairchildsemi.com/ds/BC/BC807.pdf" H 21250 9250 50  0001 L CNN
	1    21250 9250
	0    -1   -1   0   
$EndComp
$Comp
L Transistor_BJT:BC807 Q?
U 1 1 5F83134F
P 21250 9900
F 0 "Q?" V 21578 9900 50  0000 C CNN
F 1 "BC807" V 21487 9900 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 21450 9825 50  0001 L CIN
F 3 "http://www.fairchildsemi.com/ds/BC/BC807.pdf" H 21250 9900 50  0001 L CNN
	1    21250 9900
	0    -1   -1   0   
$EndComp
$Comp
L Transistor_BJT:BC807 Q?
U 1 1 5F831355
P 21250 10600
F 0 "Q?" V 21578 10600 50  0000 C CNN
F 1 "BC807" V 21487 10600 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 21450 10525 50  0001 L CIN
F 3 "http://www.fairchildsemi.com/ds/BC/BC807.pdf" H 21250 10600 50  0001 L CNN
	1    21250 10600
	0    -1   -1   0   
$EndComp
Wire Wire Line
	21050 9800 21000 9800
Wire Wire Line
	21000 9800 21000 9250
Wire Wire Line
	21450 10500 21550 10500
Wire Wire Line
	21550 10500 21550 9800
Wire Wire Line
	21450 9150 21550 9150
Connection ~ 21550 9150
Wire Wire Line
	21550 9150 21550 8950
Wire Wire Line
	21450 9800 21550 9800
Connection ~ 21550 9800
Wire Wire Line
	21550 9800 21550 9150
$Comp
L power:+3.3V #PWR?
U 1 1 5F831365
P 21550 8950
F 0 "#PWR?" H 21550 8800 50  0001 C CNN
F 1 "+3.3V" H 21565 9123 50  0000 C CNN
F 2 "" H 21550 8950 50  0001 C CNN
F 3 "" H 21550 8950 50  0001 C CNN
	1    21550 8950
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5F83136B
P 21850 10800
F 0 "R?" H 21780 10754 50  0000 R CNN
F 1 "5k6" H 21780 10845 50  0000 R CNN
F 2 "Capacitors:0805" V 21780 10800 50  0001 C CNN
F 3 "~" H 21850 10800 50  0001 C CNN
	1    21850 10800
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R?
U 1 1 5F831371
P 21850 10100
F 0 "R?" H 21780 10054 50  0000 R CNN
F 1 "5k6" H 21780 10145 50  0000 R CNN
F 2 "Capacitors:0805" V 21780 10100 50  0001 C CNN
F 3 "~" H 21850 10100 50  0001 C CNN
	1    21850 10100
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R?
U 1 1 5F831377
P 21900 9450
F 0 "R?" H 21830 9404 50  0000 R CNN
F 1 "5k6" H 21830 9495 50  0000 R CNN
F 2 "Capacitors:0805" V 21830 9450 50  0001 C CNN
F 3 "~" H 21900 9450 50  0001 C CNN
	1    21900 9450
	0    -1   -1   0   
$EndComp
Wire Wire Line
	21250 9450 21750 9450
Wire Wire Line
	21250 10100 21700 10100
Wire Wire Line
	21250 10800 21700 10800
Wire Wire Line
	20900 9350 20900 10500
Wire Wire Line
	20900 10500 21050 10500
Wire Wire Line
	20350 9150 21050 9150
Wire Wire Line
	20350 9250 21000 9250
Wire Wire Line
	20350 9350 20900 9350
$Comp
L Transistor_BJT:BC817 Q?
U 1 1 5F84B680
P 17800 6600
F 0 "Q?" V 18128 6600 50  0000 C CNN
F 1 "BC817" V 18037 6600 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 18000 6525 50  0001 L CIN
F 3 "http://www.fairchildsemi.com/ds/BC/BC817.pdf" H 17800 6600 50  0001 L CNN
	1    17800 6600
	0    1    -1   0   
$EndComp
$Comp
L Transistor_BJT:BC817 Q?
U 1 1 5F84D9EF
P 17800 7100
F 0 "Q?" V 18128 7100 50  0000 C CNN
F 1 "BC817" V 18037 7100 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 18000 7025 50  0001 L CIN
F 3 "http://www.fairchildsemi.com/ds/BC/BC817.pdf" H 17800 7100 50  0001 L CNN
	1    17800 7100
	0    1    -1   0   
$EndComp
$Comp
L Transistor_BJT:BC817 Q?
U 1 1 5F84DFF5
P 17800 7600
F 0 "Q?" V 18128 7600 50  0000 C CNN
F 1 "BC817" V 18037 7600 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 18000 7525 50  0001 L CIN
F 3 "http://www.fairchildsemi.com/ds/BC/BC817.pdf" H 17800 7600 50  0001 L CNN
	1    17800 7600
	0    1    -1   0   
$EndComp
$Comp
L Transistor_BJT:BC817 Q?
U 1 1 5F84E64B
P 17800 8100
F 0 "Q?" V 18128 8100 50  0000 C CNN
F 1 "BC817" V 18037 8100 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 18000 8025 50  0001 L CIN
F 3 "http://www.fairchildsemi.com/ds/BC/BC817.pdf" H 17800 8100 50  0001 L CNN
	1    17800 8100
	0    1    -1   0   
$EndComp
$Comp
L Transistor_BJT:BC817 Q?
U 1 1 5F84F2AD
P 17800 8550
F 0 "Q?" V 18128 8550 50  0000 C CNN
F 1 "BC817" V 18037 8550 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 18000 8475 50  0001 L CIN
F 3 "http://www.fairchildsemi.com/ds/BC/BC817.pdf" H 17800 8550 50  0001 L CNN
	1    17800 8550
	0    1    -1   0   
$EndComp
$Comp
L Transistor_BJT:BC817 Q?
U 1 1 5F84F95C
P 17800 9000
F 0 "Q?" V 18128 9000 50  0000 C CNN
F 1 "BC817" V 18037 9000 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 18000 8925 50  0001 L CIN
F 3 "http://www.fairchildsemi.com/ds/BC/BC817.pdf" H 17800 9000 50  0001 L CNN
	1    17800 9000
	0    1    -1   0   
$EndComp
Wire Wire Line
	20350 6750 21000 6750
Wire Wire Line
	20350 6850 20900 6850
Wire Wire Line
	20350 6650 21050 6650
$Comp
L My-Lib:3-dig-7-seg-display-common-anode U?
U 1 1 5F79D382
P 19600 6600
F 0 "U?" H 19925 6775 50  0000 C CNN
F 1 "3-dig-7-seg-display-common-anode" H 19925 6684 50  0000 C CNN
F 2 "" H 19600 6600 50  0001 C CNN
F 3 "" H 19600 6600 50  0001 C CNN
	1    19600 6600
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5F8671AE
P 18700 8550
F 0 "R?" H 18630 8504 50  0000 R CNN
F 1 "5k6" H 18630 8595 50  0000 R CNN
F 2 "Capacitors:0805" V 18630 8550 50  0001 C CNN
F 3 "~" H 18700 8550 50  0001 C CNN
	1    18700 8550
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R?
U 1 1 5F866FF8
P 18700 8450
F 0 "R?" H 18630 8404 50  0000 R CNN
F 1 "5k6" H 18630 8495 50  0000 R CNN
F 2 "Capacitors:0805" V 18630 8450 50  0001 C CNN
F 3 "~" H 18700 8450 50  0001 C CNN
	1    18700 8450
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R?
U 1 1 5F866DF3
P 18700 8350
F 0 "R?" H 18630 8304 50  0000 R CNN
F 1 "5k6" H 18630 8395 50  0000 R CNN
F 2 "Capacitors:0805" V 18630 8350 50  0001 C CNN
F 3 "~" H 18700 8350 50  0001 C CNN
	1    18700 8350
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R?
U 1 1 5F866C03
P 18700 8250
F 0 "R?" H 18630 8204 50  0000 R CNN
F 1 "5k6" H 18630 8295 50  0000 R CNN
F 2 "Capacitors:0805" V 18630 8250 50  0001 C CNN
F 3 "~" H 18700 8250 50  0001 C CNN
	1    18700 8250
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R?
U 1 1 5F866A39
P 18700 8150
F 0 "R?" H 18630 8104 50  0000 R CNN
F 1 "5k6" H 18630 8195 50  0000 R CNN
F 2 "Capacitors:0805" V 18630 8150 50  0001 C CNN
F 3 "~" H 18700 8150 50  0001 C CNN
	1    18700 8150
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R?
U 1 1 5F866854
P 18700 8050
F 0 "R?" H 18630 8004 50  0000 R CNN
F 1 "5k6" H 18630 8095 50  0000 R CNN
F 2 "Capacitors:0805" V 18630 8050 50  0001 C CNN
F 3 "~" H 18700 8050 50  0001 C CNN
	1    18700 8050
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R?
U 1 1 5F86670E
P 18700 7950
F 0 "R?" H 18630 7904 50  0000 R CNN
F 1 "5k6" H 18630 7995 50  0000 R CNN
F 2 "Capacitors:0805" V 18630 7950 50  0001 C CNN
F 3 "~" H 18700 7950 50  0001 C CNN
	1    18700 7950
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R?
U 1 1 5F864714
P 18700 7850
F 0 "R?" H 18630 7804 50  0000 R CNN
F 1 "5k6" H 18630 7895 50  0000 R CNN
F 2 "Capacitors:0805" V 18630 7850 50  0001 C CNN
F 3 "~" H 18700 7850 50  0001 C CNN
	1    18700 7850
	0    -1   -1   0   
$EndComp
$Comp
L Transistor_BJT:BC817 Q?
U 1 1 5F8BBE6B
P 17800 9450
F 0 "Q?" V 18128 9450 50  0000 C CNN
F 1 "BC817" V 18037 9450 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 18000 9375 50  0001 L CIN
F 3 "http://www.fairchildsemi.com/ds/BC/BC817.pdf" H 17800 9450 50  0001 L CNN
	1    17800 9450
	0    1    -1   0   
$EndComp
$Comp
L Transistor_BJT:BC817 Q?
U 1 1 5F8BC457
P 17800 9900
F 0 "Q?" V 18128 9900 50  0000 C CNN
F 1 "BC817" V 18037 9900 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 18000 9825 50  0001 L CIN
F 3 "http://www.fairchildsemi.com/ds/BC/BC817.pdf" H 17800 9900 50  0001 L CNN
	1    17800 9900
	0    1    -1   0   
$EndComp
Wire Wire Line
	18550 7850 18500 7850
Wire Wire Line
	18500 7850 18500 6500
Wire Wire Line
	18500 6500 18000 6500
Wire Wire Line
	18000 7000 18450 7000
Wire Wire Line
	18450 7000 18450 7950
Wire Wire Line
	18450 7950 18550 7950
Wire Wire Line
	18550 8050 18400 8050
Wire Wire Line
	18400 8050 18400 7500
Wire Wire Line
	18400 7500 18000 7500
Wire Wire Line
	18550 8150 18350 8150
Wire Wire Line
	18350 8150 18350 8000
Wire Wire Line
	18350 8000 18000 8000
Wire Wire Line
	18550 8250 18350 8250
Wire Wire Line
	18350 8250 18350 8450
Wire Wire Line
	18350 8450 18000 8450
Wire Wire Line
	18550 8350 18400 8350
Wire Wire Line
	18400 8350 18400 8900
Wire Wire Line
	18400 8900 18000 8900
Wire Wire Line
	18550 8450 18450 8450
Wire Wire Line
	18450 8450 18450 9350
Wire Wire Line
	18450 9350 18000 9350
Wire Wire Line
	18550 8550 18500 8550
Wire Wire Line
	18500 8550 18500 9800
Wire Wire Line
	18500 9800 18000 9800
Wire Wire Line
	17600 9800 17550 9800
Wire Wire Line
	17550 9800 17550 9350
Wire Wire Line
	17550 6500 17600 6500
Wire Wire Line
	17600 7000 17550 7000
Connection ~ 17550 7000
Wire Wire Line
	17550 7000 17550 6500
Wire Wire Line
	17600 7500 17550 7500
Connection ~ 17550 7500
Wire Wire Line
	17550 7500 17550 7000
Wire Wire Line
	17600 8000 17550 8000
Connection ~ 17550 8000
Wire Wire Line
	17550 8000 17550 7500
Wire Wire Line
	17600 8450 17550 8450
Connection ~ 17550 8450
Wire Wire Line
	17550 8450 17550 8000
Wire Wire Line
	17600 8900 17550 8900
Connection ~ 17550 8900
Wire Wire Line
	17550 8900 17550 8450
Wire Wire Line
	17600 9350 17550 9350
Connection ~ 17550 9350
Wire Wire Line
	17550 9350 17550 8900
Wire Wire Line
	19500 7350 19400 7350
Wire Wire Line
	19400 7350 19400 7850
Wire Wire Line
	19400 9850 19500 9850
Wire Wire Line
	19500 9750 19350 9750
Wire Wire Line
	19350 9750 19350 7950
Wire Wire Line
	19350 7250 19500 7250
Wire Wire Line
	19500 7150 19300 7150
Wire Wire Line
	19300 7150 19300 8050
Wire Wire Line
	19300 9650 19500 9650
Wire Wire Line
	19500 9550 19250 9550
Wire Wire Line
	19250 9550 19250 8150
Wire Wire Line
	19250 7050 19500 7050
Wire Wire Line
	19500 6950 19200 6950
Wire Wire Line
	19200 6950 19200 8250
Wire Wire Line
	19200 9450 19500 9450
Wire Wire Line
	19500 6850 19150 6850
Wire Wire Line
	19150 6850 19150 8350
Wire Wire Line
	19150 9350 19500 9350
Wire Wire Line
	19500 9250 19100 9250
Wire Wire Line
	19100 9250 19100 8450
Wire Wire Line
	19100 6750 19500 6750
Wire Wire Line
	19500 9150 19050 9150
Wire Wire Line
	19050 9150 19050 8550
Wire Wire Line
	19050 6650 19500 6650
Wire Wire Line
	18850 7850 19400 7850
Connection ~ 19400 7850
Wire Wire Line
	19400 7850 19400 9850
Wire Wire Line
	18850 7950 19350 7950
Connection ~ 19350 7950
Wire Wire Line
	19350 7950 19350 7250
Wire Wire Line
	18850 8050 19300 8050
Connection ~ 19300 8050
Wire Wire Line
	19300 8050 19300 9650
Wire Wire Line
	18850 8150 19250 8150
Connection ~ 19250 8150
Wire Wire Line
	19250 8150 19250 7050
Wire Wire Line
	18850 8250 19200 8250
Connection ~ 19200 8250
Wire Wire Line
	19200 8250 19200 9450
Wire Wire Line
	18850 8350 19150 8350
Connection ~ 19150 8350
Wire Wire Line
	19150 8350 19150 9350
Wire Wire Line
	18850 8450 19100 8450
Connection ~ 19100 8450
Wire Wire Line
	19100 8450 19100 6750
Wire Wire Line
	18850 8550 19050 8550
Connection ~ 19050 8550
Wire Wire Line
	19050 8550 19050 6650
Wire Wire Line
	17800 6800 17800 6850
Wire Wire Line
	17800 6850 17100 6850
Wire Wire Line
	17800 7300 17800 7350
Wire Wire Line
	17800 7350 17100 7350
Wire Wire Line
	17800 7800 17800 7850
Wire Wire Line
	17800 7850 17100 7850
Wire Wire Line
	17800 8300 17800 8350
Wire Wire Line
	17800 8350 17100 8350
Wire Wire Line
	17800 8750 17800 8800
Wire Wire Line
	17800 8800 17100 8800
Wire Wire Line
	17800 9200 17800 9250
Wire Wire Line
	17800 9250 17100 9250
Wire Wire Line
	17800 9650 17800 9700
Wire Wire Line
	17800 9700 17100 9700
Wire Wire Line
	17800 10100 17800 10150
Wire Wire Line
	17800 10150 17100 10150
$Comp
L Device:R R?
U 1 1 5FAA91BA
P 16950 6850
F 0 "R?" H 16880 6804 50  0000 R CNN
F 1 "5k6" H 16880 6895 50  0000 R CNN
F 2 "Capacitors:0805" V 16880 6850 50  0001 C CNN
F 3 "~" H 16950 6850 50  0001 C CNN
	1    16950 6850
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R?
U 1 1 5FAA982C
P 16950 7350
F 0 "R?" H 16880 7304 50  0000 R CNN
F 1 "5k6" H 16880 7395 50  0000 R CNN
F 2 "Capacitors:0805" V 16880 7350 50  0001 C CNN
F 3 "~" H 16950 7350 50  0001 C CNN
	1    16950 7350
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R?
U 1 1 5FAA9BE6
P 16950 7850
F 0 "R?" H 16880 7804 50  0000 R CNN
F 1 "5k6" H 16880 7895 50  0000 R CNN
F 2 "Capacitors:0805" V 16880 7850 50  0001 C CNN
F 3 "~" H 16950 7850 50  0001 C CNN
	1    16950 7850
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R?
U 1 1 5FAAA1B0
P 16950 8350
F 0 "R?" H 16880 8304 50  0000 R CNN
F 1 "5k6" H 16880 8395 50  0000 R CNN
F 2 "Capacitors:0805" V 16880 8350 50  0001 C CNN
F 3 "~" H 16950 8350 50  0001 C CNN
	1    16950 8350
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R?
U 1 1 5FAAA791
P 16950 8800
F 0 "R?" H 16880 8754 50  0000 R CNN
F 1 "5k6" H 16880 8845 50  0000 R CNN
F 2 "Capacitors:0805" V 16880 8800 50  0001 C CNN
F 3 "~" H 16950 8800 50  0001 C CNN
	1    16950 8800
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R?
U 1 1 5FAAAC4E
P 16950 9250
F 0 "R?" H 16880 9204 50  0000 R CNN
F 1 "5k6" H 16880 9295 50  0000 R CNN
F 2 "Capacitors:0805" V 16880 9250 50  0001 C CNN
F 3 "~" H 16950 9250 50  0001 C CNN
	1    16950 9250
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R?
U 1 1 5FAAB23C
P 16950 9700
F 0 "R?" H 16880 9654 50  0000 R CNN
F 1 "5k6" H 16880 9745 50  0000 R CNN
F 2 "Capacitors:0805" V 16880 9700 50  0001 C CNN
F 3 "~" H 16950 9700 50  0001 C CNN
	1    16950 9700
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R?
U 1 1 5FAAB621
P 16950 10150
F 0 "R?" H 16880 10104 50  0000 R CNN
F 1 "5k6" H 16880 10195 50  0000 R CNN
F 2 "Capacitors:0805" V 16880 10150 50  0001 C CNN
F 3 "~" H 16950 10150 50  0001 C CNN
	1    16950 10150
	0    -1   -1   0   
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 5FAAB9E0
P 17550 6300
F 0 "#PWR?" H 17550 6150 50  0001 C CNN
F 1 "+3.3V" H 17565 6473 50  0000 C CNN
F 2 "" H 17550 6300 50  0001 C CNN
F 3 "" H 17550 6300 50  0001 C CNN
	1    17550 6300
	1    0    0    -1  
$EndComp
Wire Wire Line
	17550 6500 17550 6300
Connection ~ 17550 6500
Wire Wire Line
	16500 10150 16800 10150
Wire Wire Line
	16500 8100 16500 10150
Wire Wire Line
	15650 8100 16500 8100
Wire Wire Line
	16550 9700 16800 9700
Wire Wire Line
	16550 8000 16550 9700
Wire Wire Line
	15650 8000 16550 8000
Wire Wire Line
	16600 9250 16800 9250
Wire Wire Line
	16600 7900 16600 9250
Wire Wire Line
	15650 7900 16600 7900
Wire Wire Line
	16650 7800 16650 8800
Wire Wire Line
	16650 8800 16800 8800
Wire Wire Line
	15650 7800 16650 7800
Wire Wire Line
	16700 8350 16800 8350
Wire Wire Line
	16700 7700 16700 8350
Wire Wire Line
	15650 7700 16700 7700
Wire Wire Line
	16750 7850 16800 7850
Wire Wire Line
	16750 7600 16750 7850
Wire Wire Line
	15650 7600 16750 7600
Wire Wire Line
	16750 7350 16800 7350
Wire Wire Line
	16750 7500 16750 7350
Wire Wire Line
	15650 7500 16750 7500
Wire Wire Line
	16700 7400 15650 7400
Wire Wire Line
	16700 6850 16700 7400
Wire Wire Line
	16800 6850 16700 6850
Wire Wire Line
	15700 8800 15700 8700
Wire Wire Line
	15650 8800 15700 8800
$Comp
L power:+3.3V #PWR?
U 1 1 5F7CBAA3
P 15700 8700
F 0 "#PWR?" H 15700 8550 50  0001 C CNN
F 1 "+3.3V" H 15715 8873 50  0000 C CNN
F 2 "" H 15700 8700 50  0001 C CNN
F 3 "" H 15700 8700 50  0001 C CNN
	1    15700 8700
	1    0    0    -1  
$EndComp
Wire Wire Line
	15700 7300 15700 7250
Wire Wire Line
	15650 7300 15700 7300
$Comp
L power:+3.3V #PWR?
U 1 1 5F7C8CDE
P 15700 7250
F 0 "#PWR?" H 15700 7100 50  0001 C CNN
F 1 "+3.3V" H 15715 7423 50  0000 C CNN
F 2 "" H 15700 7250 50  0001 C CNN
F 3 "" H 15700 7250 50  0001 C CNN
	1    15700 7250
	1    0    0    -1  
$EndComp
Text GLabel 13650 7800 0    50   Input ~ 0
7SEG_LATCH
Text GLabel 13650 7500 0    50   Input ~ 0
7SEG_CLK
Text GLabel 13650 7300 0    50   Input ~ 0
7SEG_DIN
Wire Wire Line
	15650 8450 15650 8200
Wire Wire Line
	14850 8450 15650 8450
Wire Wire Line
	14850 8800 14850 8450
Wire Wire Line
	13650 7300 14850 7300
Connection ~ 14500 7800
Wire Wire Line
	14500 7800 13650 7800
Connection ~ 14400 7500
Wire Wire Line
	14400 7500 13650 7500
Wire Wire Line
	14500 9300 14850 9300
Wire Wire Line
	14500 7800 14500 9300
Wire Wire Line
	14850 7800 14500 7800
Wire Wire Line
	14700 7600 14850 7600
Connection ~ 14700 8000
Wire Wire Line
	14700 7600 14700 8000
Connection ~ 14700 8200
Wire Wire Line
	14700 8000 14700 8200
Wire Wire Line
	14850 8000 14700 8000
Connection ~ 14700 9100
Wire Wire Line
	14700 8200 14700 9100
Wire Wire Line
	14850 8200 14700 8200
Wire Wire Line
	14700 9500 14700 9700
Connection ~ 14700 9500
Wire Wire Line
	14850 9500 14700 9500
Connection ~ 14700 9700
Wire Wire Line
	14700 9100 14700 9500
Wire Wire Line
	14850 9100 14700 9100
Wire Wire Line
	14700 9700 14700 9850
Wire Wire Line
	14850 9700 14700 9700
$Comp
L power:GND #PWR?
U 1 1 5F7A79C4
P 14700 9850
F 0 "#PWR?" H 14700 9600 50  0001 C CNN
F 1 "GND" H 14705 9677 50  0000 C CNN
F 2 "" H 14700 9850 50  0001 C CNN
F 3 "" H 14700 9850 50  0001 C CNN
	1    14700 9850
	1    0    0    -1  
$EndComp
Wire Wire Line
	14400 9000 14850 9000
Wire Wire Line
	14400 7500 14400 9000
Wire Wire Line
	14850 7500 14400 7500
$Comp
L SparkFun-IC-Logic:74HC595D U?
U 1 1 5F7A37BF
P 15250 9250
F 0 "U?" H 15250 9954 45  0000 C CNN
F 1 "74HC595D" H 15250 9870 45  0000 C CNN
F 2 "SO16" H 15250 9950 20  0001 C CNN
F 3 "" H 15250 9250 50  0001 C CNN
F 4 "" H 15150 9300 60  0001 C CNN "Pole4"
	1    15250 9250
	1    0    0    -1  
$EndComp
$Comp
L SparkFun-IC-Logic:74HC595D U?
U 1 1 5F7A16CC
P 15250 7750
F 0 "U?" H 15250 8454 45  0000 C CNN
F 1 "74HC595D" H 15250 8370 45  0000 C CNN
F 2 "SO16" H 15250 8450 20  0001 C CNN
F 3 "" H 15250 7750 50  0001 C CNN
F 4 "" H 15150 7800 60  0001 C CNN "Pole4"
	1    15250 7750
	1    0    0    -1  
$EndComp
Wire Wire Line
	22000 10800 22100 10800
Wire Wire Line
	22100 10800 22100 11100
Wire Wire Line
	22100 11100 16350 11100
Wire Wire Line
	16350 11100 16350 8900
Wire Wire Line
	16350 8900 15650 8900
Wire Wire Line
	15650 9000 16300 9000
Wire Wire Line
	16300 11150 22150 11150
Wire Wire Line
	22150 11150 22150 10100
Wire Wire Line
	22150 10100 22000 10100
Wire Wire Line
	16300 9000 16300 11150
Wire Wire Line
	22050 9450 22200 9450
Wire Wire Line
	22200 9450 22200 11200
Wire Wire Line
	22200 11200 16250 11200
Wire Wire Line
	16250 11200 16250 9100
Wire Wire Line
	15650 9100 16250 9100
Wire Wire Line
	15650 9200 16200 9200
Wire Wire Line
	16200 9200 16200 11250
Wire Wire Line
	16200 11250 22250 11250
Wire Wire Line
	22250 11250 22250 8300
Wire Wire Line
	22250 8300 22000 8300
Wire Wire Line
	22000 7600 22300 7600
Wire Wire Line
	22300 11300 16150 11300
Wire Wire Line
	16150 11300 16150 9300
Wire Wire Line
	16150 9300 15650 9300
Wire Wire Line
	22300 7600 22300 11300
Wire Wire Line
	22050 6950 22350 6950
Wire Wire Line
	22350 6950 22350 11350
Wire Wire Line
	22350 11350 16100 11350
Wire Wire Line
	16100 11350 16100 9400
Wire Wire Line
	16100 9400 15650 9400
Wire Notes Line
	12900 11850 22600 11850
Wire Notes Line
	22600 11850 22600 5850
Wire Notes Line
	22600 5850 12900 5850
Wire Notes Line
	12900 5850 12900 11850
$EndSCHEMATC
