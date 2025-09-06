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
        engineConfiguration->clt.config.bias_resistor = 2200;
        engineConfiguration->iat.config.bias_resistor = 2200;

        engineConfiguration->canRxPin = Gpio::B8;
        engineConfiguration->canTxPin = Gpio::B9;
        engineConfiguration->can2RxPin = Gpio::B5;
        engineConfiguration->can2TxPin = Gpio::B6;

        engineConfiguration->is_enabled_spi_3 = true;
        engineConfiguration->spi3mosiPin = Gpio::C12;
        engineConfiguration->spi3misoPin = Gpio::C11;
        engineConfiguration->spi3sckPin = Gpio::C10;

        engineConfiguration->is_enabled_spi_4 = true;
        engineConfiguration->spi4misoPin = Gpio::E5;
        engineConfiguration->spi4sckPin = Gpio::E2;

        engineConfiguration->sdCardSpiDevice = SPI_DEVICE_3;
        engineConfiguration->sdCardCsPin = Gpio::D0;

        engineConfiguration->max31855spiDevice = SPI_DEVICE_4;
	engineConfiguration->max31855_cs[0] = Gpio::F2;
	engineConfiguration->max31855_cs[1] = Gpio::F1;

        engineConfiguration->vbattAdcChannel = EFI_ADC_10;
}

void setBoardDefaultConfiguration(void) {
        engineConfiguration->vbattDividerCoeff = (8.2 + 1) / 1;
        engineConfiguration->adcVcc = 3.3f;
        engineConfiguration->analogInputDividerCoefficient = 1.516f;

        engineConfiguration->etbIo[0].controlPin = Gpio::H15;
        engineConfiguration->etbIo[0].directionPin1 = Gpio::G7;
        engineConfiguration->etbIo[0].disablePin = Gpio::G8;
        engineConfiguration->etbIo[0].directionPin2 = Gpio::Unassigned;
        engineConfiguration->etbIo[1].controlPin = Gpio::I0;
        engineConfiguration->etbIo[1].directionPin1 = Gpio::G6;
        engineConfiguration->etbIo[1].disablePin = Gpio::I1;
        engineConfiguration->etbIo[1].directionPin2 = Gpio::Unassigned;
        engineConfiguration->etb_use_two_wires = false;
}
