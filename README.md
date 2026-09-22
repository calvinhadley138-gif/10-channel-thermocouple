# 10-Channel Thermocouple Reader (Arduino + MAX6675)

An Arduino sketch that reads temperature from **10 K-type thermocouples** simultaneously using 10 MAX6675 breakout boards on a single shared SPI bus, and prints all readings (in °F) to the Serial Monitor once per second.

## What you need

- 1x Arduino (Uno or compatible)
- 10x MAX6675 thermocouple amplifier breakout boards
- 10x K-type thermocouples
- Jumper wires

## Wiring

All 10 MAX6675 boards share the same clock, data, and power lines. Each board has its own individual Chip Select (CS) pin so the Arduino can talk to them one at a time.

**Shared connections (wire all 10 boards to these):**

| MAX6675 Pin | Arduino Pin |
|---|---|
| SCK | Pin 6 |
| SO  | Pin 4 |
| VCC | 5V |
| GND | GND |

**Individual CS pins:**

| Thermocouple # | CS Pin |
|---|---|
| 1 | Pin 2 |
| 2 | Pin 3 |
| 3 | Pin 5 |
| 4 | Pin 7 |
| 5 | Pin 8 |
| 6 | A2 |
| 7 | A3 |
| 8 | A4 |
| 9 | A0 |
| 10 | A1 |

Only 12 Arduino pins are used in total (2 shared + 10 CS). Pins 9, 10, and 13 are free for other uses (e.g. an LCD display, SD card logger, etc).

## Software setup

1. Install the **Arduino IDE** (free, from [arduino.cc](https://www.arduino.cc/en/software)) if you don't already have it.
2. In the Arduino IDE, go to **Sketch → Include Library → Manage Libraries**, search for **"MAX6675"**, and install the library by **Adafruit**.
3. Download `Ten_thermocouple_code_V1.ino` from this repository.
4. Open it in the Arduino IDE.
5. Select your board and port under **Tools**, then click **Upload**.
6. Open the **Serial Monitor** (Tools → Serial Monitor), set the baud rate to **9600**, and you should see all 10 temperatures printing every second.

## Troubleshooting

- **Readings look inverted** (temperature goes up in ice water, down on a hot surface): swap the two thermocouple wire leads at the MAX6675 input terminals. This is a thermocouple polarity issue, not a wiring or code issue.
- **A channel reads a strange/constant value:** double check that channel's CS pin connection, and make sure no two CS pins are accidentally wired together.
- **Nothing prints:** confirm the Serial Monitor baud rate is set to 9600, and that the correct board/port is selected in the Arduino IDE.

## License

Feel free to use, modify, and build on this project.
