# Imports
from serial import Serial
from datetime import datetime
from numpy import frombuffer, uint8

# Variables
serial = Serial(
    port = "COM3",
    baudrate = 921600
)
received = 0
frequencies = []
last = datetime.now()

# Main
if __name__ == "__main__":
    try:
        while True:
            if serial.read(1) == b's':
                matrix = [frombuffer(
                    serial.read(40),
                    uint8
                )
                    for lane in range(40)]

                current = datetime.now()
                frequency = 1 / (current - last).total_seconds()
                last = current
                received += 1
                frequencies.append(frequency)

                print(f"\rFrequency of {sum(frequencies) / len(frequencies)}Hz based on {received} received matrix's.",
                      end = '')
    except KeyboardInterrupt:
        serial.close()