#include "pch.h"

static void setInjectorPins() {
	engineConfiguration->injectionPins[0] = Gpio::B14;
	engineConfiguration->injectionPins[1] = Gpio::B15;
	engineConfiguration->injectionPins[2] = Gpio::D8;
	engineConfiguration->injectionPins[3] = Gpio::D9;
	engineConfiguration->injectionPins[4] = Gpio::D10;
	engineConfiguration->injectionPins[5] = Gpio::D11;
}

static void setIgnitionPins() {
	engineConfiguration->ignitionPins[0] = Gpio::G9;
	engineConfiguration->ignitionPins[1] = Gpio::G11;
	engineConfiguration->ignitionPins[2] = Gpio::G13;
	engineConfiguration->ignitionPins[3] = Gpio::G10;
	engineConfiguration->ignitionPins[4] = Gpio::G12;
	engineConfiguration->ignitionPins[5] = Gpio::G14;
}

static void setEtbConfig() {
	engineConfiguration->etbIo[0].controlPin = Gpio::E8;
	engineConfiguration->etbIo[0].directionPin1 = Gpio::E7;
	engineConfiguration->etbIo[0].disablePin = Gpio::E9;
	engineConfiguration->etbIo[0].directionPin2 = Gpio::Unassigned;
	engineConfiguration->etb_use_two_wires = false;
}

static void setupVbatt() {
	engineConfiguration->analogInputDividerCoefficient = 1.516f;
	engineConfiguration->vbattDividerCoeff = (3.277 + 0.51) / 0.51;
	engineConfiguration->vbattAdcChannel = EFI_ADC_11;
	engineConfiguration->adcVcc = 3.3f;
}

Gpio getCommsLedPin() {
	return Gpio::Unassigned;
}

Gpio getRunningLedPin() {
	return Gpio::Unassigned;
}

Gpio getWarningLedPin() {
	return Gpio::Unassigned;
}

void setBoardConfigOverrides() {
	setEtbConfig();

	engineConfiguration->clt.config.bias_resistor = 2200;
	engineConfiguration->iat.config.bias_resistor = 2200;
	engineConfiguration->oilTempSensor.config.bias_resistor = 330;

	engineConfiguration->canRxPin = Gpio::D0;
	engineConfiguration->canTxPin = Gpio::D1;

	engineConfiguration->is_enabled_spi_1 = true;
	engineConfiguration->spi1mosiPin = Gpio::B5;
	engineConfiguration->spi1misoPin = Gpio::B4;
	engineConfiguration->spi1sckPin = Gpio::B3;

	engineConfiguration->is_enabled_spi_3 = true;
	engineConfiguration->spi3mosiPin = Gpio::C12;
	engineConfiguration->spi3misoPin = Gpio::C11;
	engineConfiguration->spi3sckPin = Gpio::C10;

	engineConfiguration->max31855spiDevice = SPI_DEVICE_1;
	engineConfiguration->max31855_cs[0] = Gpio::B9;

	engineConfiguration->sdCardSpiDevice = SPI_DEVICE_3;
	engineConfiguration->sdCardCsPin = Gpio::D2;
}

void setBoardDefaultConfiguration(void) {
	setInjectorPins();
	setIgnitionPins();
	setupVbatt();

	engineConfiguration->fuelPumpPin = Gpio::G5;

	engineConfiguration->canWriteEnabled = true;
	engineConfiguration->canReadEnabled = true;
	engineConfiguration->canSleepPeriodMs = 10;
	engineConfiguration->canBaudRate = B500KBPS;
}
