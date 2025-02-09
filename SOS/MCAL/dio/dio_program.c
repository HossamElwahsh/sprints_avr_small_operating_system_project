/**
 * @file    :   dio_program.h
 * @author  :   Hossam Elwahsh - https://github.com/HossamElwahsh
 * @brief   :   Program file contains all Digital Input Output (DIO) functions' implementation.
 * @version :   2.0
 * @date    :   2023-05-29
 *
 * @copyright Copyright (c) 2023
 */

#include "dio_interface.h"
#include "dio_private.h"

/* Private Prototypes */
static enu_dio_error_t_ dio_pin_port_check(enu_dio_port_t_ enu_dio_port, enu_dio_pin_t_ enu_dio_pin);

/**
 * @brief Initializes a pin of the DIO interface with a given direction
 *
 * This function initializes a pin of the Digital Input/Output (DIO) interface with the given direction.
 * It sets the Data Direction Register (DDR) of the port to the given direction for the specified pin.
 *
 * @param[in] enu_dio_pin The pin number of the DIO interface to initialize (DIO_U8_PIN_0 to DIO_U8_PIN_7)
 * @param[in] enu_dio_port The port number of the DIO interface to initialize (DIO_PORT_A, DIO_PORT_B, DIO_PORT_C or DIO_PORT_D)
 * @param[in] enu_dio_direction The direction to set for the pin (DIO_IN or DIO_OUT)
 *
 * @return An enu_dio_error_t_ value indicating the success or failure of the operation
 *         (DIO_OK if the operation succeeded, DIO_ERROR otherwise)
 */
enu_dio_error_t_ dio_init(enu_dio_port_t_ enu_dio_port, enu_dio_pin_t_ enu_dio_pin, enu_dio_direction_t_ enu_dio_direction) {

    enu_dio_error_t_ enu_l_dio_error = dio_pin_port_check(enu_dio_port, enu_dio_pin);
    if(enu_l_dio_error != DIO_OK)
    {
        return enu_l_dio_error;
    }

    switch (enu_dio_port) {

        case DIO_PORT_A:
            if (enu_dio_direction == DIO_OUT) {
                SET_BIT(DIO_U8_DDR_A_REG, enu_dio_pin); // set pin as output
            } else if (enu_dio_direction == DIO_IN) {
                CLR_BIT(DIO_U8_DDR_A_REG, enu_dio_pin); // set pin as input
            } else {
                // error handling
                return DIO_WRONG_PIN_VAL;
            }

            break;
        case DIO_PORT_B:
            if (enu_dio_direction == DIO_OUT) {
                SET_BIT(DIO_U8_DDR_B_REG, enu_dio_pin); // set pin as output
            } else if (enu_dio_direction == DIO_IN) {
                CLR_BIT(DIO_U8_DDR_B_REG, enu_dio_pin); // set pin as input
            } else {
                // error handling
                return DIO_WRONG_PIN_VAL;
            }
            break;
        case DIO_PORT_C:
            if (enu_dio_direction == DIO_OUT) {
                SET_BIT(DIO_U8_DDR_C_REG, enu_dio_pin); // set pin as output
            } else if (enu_dio_direction == DIO_IN) {
                CLR_BIT(DIO_U8_DDR_C_REG, enu_dio_pin); // set pin as input
            } else {
                // error handling
                return DIO_WRONG_PIN_VAL;
            }
            break;
        case DIO_PORT_D:
            if (enu_dio_direction == DIO_OUT) {
                SET_BIT(DIO_U8_DDR_D_REG, enu_dio_pin); // set pin as output
            } else if (enu_dio_direction == DIO_IN) {
                CLR_BIT(DIO_U8_DDR_D_REG, enu_dio_pin); // set pin as input
            } else {
                // error handling
                return DIO_WRONG_PIN_VAL;
            }
            break;
        default:
            // bad config
            return DIO_WRONG_PORT;
    }
    return DIO_OK;
}


/**
 * @brief Reads the value of a pin on a port of the DIO interface
 *
 * This function reads the value of a pin on a port of the Digital Input/Output (DIO) interface. It returns
 * the value of the specified pin as a 0 or 1 in the enu_dio_pin_val parameter. The pin number and port number
 * must be valid and in range for the DIO interface to function correctly.
 *
 * @param[in] enu_dio_pin The pin number to read from the port
 * @param[in] enu_dio_port The port number of the DIO interface to read from
 * @param[out] enu_dio_pin_val Pointer to an unsigned 8-bit integer where the value of the pin will be stored
 *
 * @return An enu_dio_error_t_ value indicating the success or failure of the operation
 *         (DIO_OK if the operation succeeded, DIO_ERROR otherwise)
 */
enu_dio_error_t_ dio_read(enu_dio_port_t_ enu_dio_port, enu_dio_pin_t_ enu_dio_pin, enu_dio_pin_val_t_ * enu_dio_pin_val)
{
    enu_dio_error_t_ enu_l_dio_error = dio_pin_port_check(enu_dio_port, enu_dio_pin);
    if(enu_l_dio_error != DIO_OK)
    {
        return enu_l_dio_error;
    }

    switch (enu_dio_port) {
        case DIO_PORT_A:
            *enu_dio_pin_val = GET_BIT(DIO_U8_PIN_A_REG, enu_dio_pin);
            return DIO_OK;
        case DIO_PORT_B:
            *enu_dio_pin_val = GET_BIT(DIO_U8_PIN_B_REG, enu_dio_pin);
            return DIO_OK;
        case DIO_PORT_C:
            *enu_dio_pin_val = GET_BIT(DIO_U8_PIN_C_REG, enu_dio_pin);
            return DIO_OK;
        case DIO_PORT_D:
            *enu_dio_pin_val = GET_BIT(DIO_U8_PIN_D_REG, enu_dio_pin);
            return DIO_OK;

        default:
            return DIO_WRONG_PORT;
    }
}


/**
 * @brief Writes a digital value to a specific pin in a specific port.
 *
 * This function writes a digital value to a specific pin in a specific port.
 * It first checks if the given pin number is valid or not, and if it's not valid, it returns an error.
 * If the pin number is valid, it writes the value to the specified port using the WRITE_BIT macro.
 * If the given value is not a valid digital value, the function returns an error.
 *
 * @param[in] enu_dio_pin The number of the pin to write to. (DIO_U8_PIN_0 to DIO_U8_PIN_7)
 * @param[in] enu_dio_port The port number to write to. (DIO_PORT_A, DIO_PORT_B, DIO_PORT_C or DIO_PORT_D)
 * @param[in] u8_a_value The digital value to write (either DIO_U8_PIN_HIGH or DIO_U8_PIN_LOW).
 *
 * @return enu_dio_error_t_ Returns DIO_OK if the write is successful, DIO_ERROR otherwise.
    */
enu_dio_error_t_ dio_write(enu_dio_port_t_ enu_dio_port, enu_dio_pin_t_ enu_dio_pin, enu_dio_pin_val_t_ enu_dio_pin_val)
{
    enu_dio_error_t_ enu_l_dio_error = dio_pin_port_check(enu_dio_port, enu_dio_pin);
    if(enu_l_dio_error != DIO_OK)
    {
        return enu_l_dio_error;
    }
    if(enu_dio_pin_val >= DIO_PIN_VAL_TOTAL)
    {
        return DIO_WRONG_PIN_VAL;
    }

    switch (enu_dio_port) {
        case DIO_PORT_A:
            WRITE_BIT(DIO_U8_PORT_A_REG, enu_dio_pin, enu_dio_pin_val);
            break;
        case DIO_PORT_B:
            WRITE_BIT(DIO_U8_PORT_B_REG, enu_dio_pin, enu_dio_pin_val);
            break;
        case DIO_PORT_C:
            WRITE_BIT(DIO_U8_PORT_C_REG, enu_dio_pin, enu_dio_pin_val);
            break;
        case DIO_PORT_D:
            WRITE_BIT(DIO_U8_PORT_D_REG, enu_dio_pin, enu_dio_pin_val);
            break;
        case DIO_PORT_TOTAL:
            return DIO_WRONG_PORT;
    }
    return DIO_OK;
}


/**
 * @brief Toggles the state of a pin in the specified port.
 *
 * This function toggles the state of a pin in the specified port.
 *
 * @param[in] enu_dio_pin The pin number to toggle. (DIO_U8_PIN_0 to DIO_U8_PIN_7)
 * @param[in] enu_dio_port The port to which the pin belongs. (DIO_PORT_A, DIO_PORT_B, DIO_PORT_C or DIO_PORT_D)
 * @return enu_dio_error_t_ Returns DIO_OK on success or DIO_ERROR if an error occurred.
 */
enu_dio_error_t_ dio_toggle(enu_dio_port_t_ enu_dio_port, enu_dio_pin_t_ enu_dio_pin)
{
    enu_dio_error_t_ enu_l_dio_error = dio_pin_port_check(enu_dio_port, enu_dio_pin);
    if(enu_l_dio_error != DIO_OK)
    {
        return enu_l_dio_error;
    }

    enu_dio_pin_val_t_ val = DIO_PIN_LOW;
    enu_l_dio_error = dio_read(enu_dio_port, enu_dio_pin, &val);
    if (enu_l_dio_error == DIO_OK) {
        // toggle bit
        val = (val == DIO_PIN_LOW) ? DIO_PIN_HIGH : DIO_PIN_LOW;

        dio_write(enu_dio_port, enu_dio_pin, val);
        return DIO_OK;
    } else {
        return DIO_READ_ERROR;
    }
}

/**
 * @brief Initializes a port of the DIO interface with a given direction and mask
 *
 * This function initializes a port of the Digital Input/Output (DIO) interface with the given direction
 * and mask. It sets the Data Direction Register (DDR) of the port to the given direction, while masking
 * off any bits that are not specified in the mask parameter. The DDR determines whether the corresponding
 * pins of the port are inputs or outputs.
 *
 * @param[in] enu_dio_port The port number of the DIO interface to initialize (DIO_PORT_A, DIO_PORT_B, DIO_PORT_C or DIO_PORT_D)
 * @param[in] en_a_portDir The direction to set for the port (INPUT or OUTPUT)
 * @param[in] u8_a_mask The mask to use when setting the DDR of the port (DIO_NO_MASK, DIO_MASK_BITS_n..)
 *
 * @return An enu_dio_error_t_ value indicating the success or failure of the operation
 *         (DIO_OK if the operation succeeded, DIO_ERROR otherwise)
 */
enu_dio_error_t_ dio_port_init(enu_dio_port_t_ enu_dio_port, enu_dio_port_direction_t_ en_a_portDir, uint8_t_ u8_a_mask) {
    if(u8_a_mask == DIO_MASK_ZERO) u8_a_mask = DIO_NO_MASK;

    // output only masked u8_a_byte u8_a_value (used karnaugh map to calculate expression)
    switch (enu_dio_port) {
        case DIO_PORT_A:
            DIO_U8_DDR_A_REG = ((~u8_a_mask) & DIO_U8_DDR_A_REG) | (u8_a_mask & en_a_portDir);
            break;
        case DIO_PORT_B:
            DIO_U8_DDR_B_REG = ((~u8_a_mask) & DIO_U8_DDR_B_REG) | (u8_a_mask & en_a_portDir);
            break;
        case DIO_PORT_C:
            DIO_U8_DDR_C_REG = ((~u8_a_mask) & DIO_U8_DDR_C_REG) | (u8_a_mask & en_a_portDir);
            break;
        case DIO_PORT_D:
            DIO_U8_DDR_D_REG = ((~u8_a_mask) & DIO_U8_DDR_D_REG) | (u8_a_mask & en_a_portDir);
            break;
        default:
            return DIO_WRONG_PORT;
    }
    return DIO_OK;
}

/**
 * @brief Writes a byte to a port of the DIO interface
 *
 * This function writes a byte to a port of the Digital Input/Output (DIO) interface. It sets the output
 * value of the Data Register (PORT) of the port to the given byte, while masking off any bits that are not
 * specified in the mask parameter. The PORT determines the state of the corresponding pins of the port that
 * are configured as outputs.
 *
 * @param[in] enu_dio_port The port number of the DIO interface to write to (DIO_PORT_A, DIO_PORT_B, DIO_PORT_C or DIO_PORT_D)
 * @param[in] enu_dio_port_val The byte value to write to port (DIO_U8_PORT_LOW, DIO_U8_PORT_HIGH)
 * @param[in] u8_a_mask The mask to use when setting the PORT of the port (DIO_NO_MASK, DIO_MASK_BITS_n..)
 *
 * @return An enu_dio_error_t_ value indicating the success or failure of the operation
 *         (DIO_OK if the operation succeeded, DIO_ERROR otherwise)
 */
enu_dio_error_t_ dio_port_write(enu_dio_port_t_ enu_dio_port, enu_dio_port_val_t_ enu_dio_port_val, uint8_t_ u8_a_mask)
{
    if(u8_a_mask == DIO_MASK_ZERO) u8_a_mask = DIO_NO_MASK;
    if(enu_dio_port_val != DIO_PORT_LOW && enu_dio_port_val != DIO_PORT_HIGH)
    {
        return DIO_WRONG_PORT_VAL;
    }

    // output only masked enu_dio_port_val u8_a_value (used karnaugh map to calculate expression)
    switch (enu_dio_port) {
        case DIO_PORT_A:
            DIO_U8_PORT_A_REG = ((~u8_a_mask) & DIO_U8_PORT_A_REG) | (u8_a_mask & enu_dio_port_val);
            break;
        case DIO_PORT_B:
            DIO_U8_PORT_B_REG = ((~u8_a_mask) & DIO_U8_PORT_B_REG) | (u8_a_mask & enu_dio_port_val);
            break;
        case DIO_PORT_C:
            DIO_U8_PORT_C_REG = ((~u8_a_mask) & DIO_U8_PORT_C_REG) | (u8_a_mask & enu_dio_port_val);
            break;
        case DIO_PORT_D:
            DIO_U8_PORT_D_REG = ((~u8_a_mask) & DIO_U8_PORT_D_REG) | (u8_a_mask & enu_dio_port_val);
            break;
        default:
            return DIO_ERROR;
    }
    return DIO_OK;
}

/**
 * @brief Toggles the state of the pins of a port of the DIO interface
 *
 * This function toggles the state of the pins of a port of the Digital Input/Output (DIO) interface.
 * It XORs the PORT of the port with the given mask, which inverts the state of the pins that correspond
 * to the bits set in the mask. The PORT determines the state of the corresponding pins of the port that
 * are configured as outputs.
 *
 * @param[in] enu_dio_port The port number of the DIO interface to toggle (DIO_PORT_A, DIO_PORT_B, DIO_PORT_C or DIO_PORT_D)
 * @param[in] u8_a_mask The mask to use when toggling the PORT of the port (DIO_NO_MASK, DIO_MASK_BITS_n..)
 *
 * @return An enu_dio_error_t_ value indicating the success or failure of the operation
 *         (DIO_OK if the operation succeeded, DIO_ERROR otherwise)
 */
enu_dio_error_t_ dio_port_toggle(enu_dio_port_t_ enu_dio_port, uint8_t_ u8_a_mask)
{
    if(u8_a_mask == DIO_MASK_ZERO) u8_a_mask = DIO_NO_MASK;
    switch (enu_dio_port) {
        case DIO_PORT_A:
            DIO_U8_PORT_A_REG ^= u8_a_mask;
            break;
        case DIO_PORT_B:
            DIO_U8_PORT_B_REG ^= u8_a_mask;
            break;
        case DIO_PORT_C:
            DIO_U8_PORT_C_REG ^= u8_a_mask;
            break;
        case DIO_PORT_D:
            DIO_U8_PORT_D_REG ^= u8_a_mask;
            break;
        default:
            return DIO_ERROR;
    }
    return DIO_OK;
}

/**
 * Private helper function to check for valid pin/port numbers
 * @param enu_dio_port port number
 * @param enu_dio_pin pin number
 * @return DIO_OK, DIO_WRONG_PIN, DIO_WRONG_PORT
 */
static enu_dio_error_t_ dio_pin_port_check(enu_dio_port_t_ enu_dio_port, enu_dio_pin_t_ enu_dio_pin)
{
    if(enu_dio_pin >= DIO_PIN_TOTAL) return DIO_WRONG_PIN;
    if(enu_dio_port >= DIO_PORT_TOTAL) return DIO_WRONG_PORT;
    return DIO_OK;
}