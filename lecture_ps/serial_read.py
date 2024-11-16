import serial
import csv
import datetime
now = datetime.datetime.now()
date = now.strftime("%Y%m%d%H%M%S")

# Liste des colonnes dans le CSV
header = ["time", "PS1", "PS2", "PS3"]


def adc_to_presure( value:int )->int:
    p = (25*(int(value)*5/1023)-0.5)/4
    p = round(p, 2)
    return p


# Changer le port COM si nécessaire (voir Arduino IDE)
arduino = serial.Serial(port=" Serial Port (USB)", baudrate=115200, timeout=.1)
separator = ','


with open(f"pressure_data_inj_{date}.csv", "w", newline='') as file:
    writer = csv.writer(file)
    # Mettre les noms des colonnes en haut du CSV
    writer.writerow(header)

    while True:
        try:
            # Lit les valeurs renvoyées par l'ADC
            result = arduino.readline().decode().strip()
            array_data = result.split(separator)
            # print(f"array_data={array_data} len={len(array_data)}")
            if len(array_data) != 4:
                continue
            milli = int(array_data[0])
            pressure = [ milli ]
            for i in range(1, 4):
                # Formule pour convertir la valeur de l'ADC en pression
                a = adc_to_presure(result[i])
                pressure.append(a)
            # Ecrire les nouvelles pressions dans le CSV
            writer.writerow(pressure)
            print(pressure)

        except KeyboardInterrupt:
            file.close()
            print('end of serial convertor')
            break
        except IndexError:
            pass
        except ValueError: 
            pass

