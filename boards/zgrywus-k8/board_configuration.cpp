#include "pch.h"

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
        engineConfiguration->etbIo[0].controlPin = Gpio::E7;
        engineConfiguration->etbIo[0].directionPin1 = Gpio::E9;
        engineConfiguration->etbIo[0].disablePin = Gpio::E8;
        engineConfiguration->etbIo[0].directionPin2 = Gpio::Unassigned;
        engineConfiguration->etb_use_two_wires = false;

        engineConfiguration->clt.config.bias_resistor = 2200;
        engineConfiguration->iat.config.bias_resistor = 2200;

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

        engineConfiguration->vbattAdcChannel = EFI_ADC_11;
}

void setBoardDefaultConfiguration(void) {
        engineConfiguration->adcVcc = 3.3f;
        engineConfiguration->vbattDividerCoeff = (3.277 + 0.51) / 0.51;
        engineConfiguration->analogInputDividerCoefficient = 1.516f;
}
