# Imports
from socket import socket, AF_INET, SOCK_DGRAM
from datetime import datetime

# Variables
udpServer = socket(AF_INET, SOCK_DGRAM)
received = 0
start = datetime.now()
matrices = []

# Main
if __name__ == "__main__":
    try:
        udpServer.bind(("0.0.0.0", "<SERVER PORT>"))

        while True:
            header, source = udpServer.recvfrom(1600)

            if header == b's':
                try:
                    payload, source = udpServer.recvfrom(1600)
                    missing = 1600 - len(payload)

                    if missing != 0:
                        payload = bytearray(payload)
                        payload.extend(
                            udpServer.recv(missing)
                        )
                    payload = [int(i) for i in payload]

                    current = datetime.now()
                    difference = (current - start).total_seconds()
                    frequency = received / difference
                    received += 1
                except Exception:
                    continue

                print(f"\rFrequency of {frequency}Hz based on {received} received matrix's.",
                      end='')
    except (KeyboardInterrupt, Exception) as e:
        udpServer.close()
