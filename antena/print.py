import re

mes = "03:23:12  $GNGGA,032312.00,3738.01098,N,12704.60079,E,1,12,0.74,49.1,M,18.6,M,,*77"
mes +="03:23:12  $GNGSA,A,3,01,07,08,30,17,21,27,14,,,,,1.10,0.74,0.82,1*00"
mes +="03:23:12  $GNGSA,A,3,78,86,76,88,87,,,,,,,,1.10,0.74,0.82,2*04"
mes +="03:23:12  $GNGSA,A,3,31,33,24,10,26,,,,,,,,1.10,0.74,0.82,3*0B"
mes +="03:23:12  $GNGSA,A,3,09,23,11,34,07,28,,,,,,,1.10,0.74,0.82,4*0F"
mes += "03:24:05  $GNGLL,3738.01132,N,12704.60098,E,032405.00,A,A*7E\n"
mes += "03:24:05  $GLGSV,1,1,04,70,00,016,,71,03,060,,77,74,178,,81,02,233,,0*7A\n"
mes += "03:24:05  $GAGSV,2,1,05,10,36,216,19,24,50,315,28,26,11,041,19,31,76,119,20,2*76\n"

mes_box=[]
gps_data=[]
gps_point=[]


def convert_gps(fields):
    latitude = float(fields[3][:2]) + float(fields[3][2:]) / 60.0
    latitude = round(latitude,6)
    if fields[3] == "S":
        latitude = -latitude

    longitude = float(fields[5][:3]) + float(fields[5][3:]) / 60.0
    longitude = round(longitude,6)
    if fields[5] == "W":
        longitude = -longitude

    altitude = float(fields[10])

    return latitude,longitude, altitude


#mes_box= mes.split("\n")

i=0

#for i in range(len(mes_box)):
    #gps_data = re.split(r'[,\s]+', mes_box[i])
    #if len(gps_data)>1:
        #if "GNGGA" in gps_data[1]: 
         #gps_point = convert_gps(gps_data)
         #print(gps_point)

         
    #gps_data.clear()

with open('E:\\altera\\gps_data.txt', 'r') as f:
    for line in f:
        gps_data = re.split(r'[,\s]+', line)
        if len(gps_data)>1:
         if "GNGGA" in gps_data[1]: 
             gps_point = convert_gps(gps_data)
             print(gps_point)

         
    gps_data.clear()
       


    

