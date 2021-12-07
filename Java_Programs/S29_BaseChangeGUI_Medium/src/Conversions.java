import java.util.IllegalFormatException;
import java.util.Locale;

/**
 *  An abstract class whose methods can be used to convert a number in one base to the equivalent in another base.
 *  (Within bases 2 through 36). Because the class is abstract, no instances of it can be made, and only its static
 *  methods can be used.
 *
 * @author Austin Piper <austin-piper@uiowa.edu></austin-piper@uiowa.edu>
 * @version 1.0
 * @since 4/5/2021
 */
public abstract class Conversions {

    /**
     * Converts a given inputted number, with its base given (bases 2 through 36 are allowed), into base 10.
     *
     * @param input_number The number to be converted into base 10
     * @param base The base of the input_number
     * @return The input_number, but in base 10
     * @throws IllegalArgumentException when a base less than 2 or greater than 36 is given
     * @throws NotInBaseException when the input_number includes a character that is not part of the given base
     */
    public static int toDecimal(String input_number, int base)
    {
        input_number = input_number.toUpperCase(); //This allows lowercase inputs to work with this method

        Boolean isNegative; //Is input_number negative

        if(input_number.charAt(0) == '-')
        {
            isNegative = true;
        }
        else
        {
            isNegative = false;
        }

        if (base < 2 || base > 36) //If the inputted base is invalid
        {
            throw new IllegalArgumentException("The given base is invalid");
        }

        int decimalized = 0; //This is where the translated output will go
        int temp;

        for (int i = 0; i < input_number.length(); i++)
        {
            if (input_number.charAt(i) >= '0' && input_number.charAt(i) <= '9') {

                if (Character.getNumericValue(input_number.charAt(i)) >= base) //If the input_number contains a character that
                {                                                              //does not belong in the given base
                    throw new NotInBaseException();
                }

                decimalized += (Character.getNumericValue(input_number.charAt(i)) * Math.pow(base, (input_number.length() - 1 - i)));
            }
            else if (input_number.charAt(i) >= 'A' && input_number.charAt(i) <= 'Z') //Convert alphabetic digits to base-10 numeric form
            {                                                                         //using the ASCII Table
                temp = input_number.charAt(i) - 55;

                if (temp >= base) //If the input_number contains a character that does not belong in the given base
                {
                    throw new NotInBaseException();
                }

                decimalized += temp * Math.pow(base, (input_number.length() - 1 - i));
            }
        }

        if (isNegative)
        {
            decimalized = decimalized * -1;
        }

        return decimalized;
    }


    /**
     * Converts an inputted number in base 10 to the base given by new_base (bases 2 through 36 are allowed), and returns
     * the output as a String
     *
     * @param decimal_form The base 10 integer to be converted
     * @param new_base The base which decimal_form is to be converted to
     * @return decimal_form, but in the new base. Note that it is returned as a String
     */
    public static String decimalToBase(int decimal_form, int new_base) {

        if (new_base < 2 || new_base > 36) //If the inputted base is not allowed
        {
            throw new IllegalArgumentException("The given base is invalid");
        }

        Boolean isNegative;
        if (decimal_form < 0)
        {
            isNegative = true;
            decimal_form = decimal_form * -1; //The negative sign is re-added once the conversion is done
        }
        else
        {
            isNegative = false;
        }

        String output = "";
        String string_form = String.valueOf(decimal_form);
        int remainder = 0;
        int quotient = decimal_form / new_base;


        remainder = decimal_form % new_base;
        int remainder_buffer = remainder; //remainder_buffer is needed because calculations need to be done
                                          //with the same 'remainder' number twice

        if (decimal_form < new_base) //If the inputted decimal_form number is smaller than the given new_base
        {
            if (decimal_form > 9 && decimal_form < new_base) //If the current digit needs to be represented with a letter
            {
                remainder_buffer += 55; //This turns 'temp' into ASCII format
            }
            else //If the current digit can be represented with a numeric (0 through 9)
            {
                remainder_buffer += 48; //Again, this turns 'temp' into ASCII format
            }

            output = Character.toString((char) remainder_buffer) + output;

        }
        else
        {

            if (remainder > 9 && remainder < new_base) //If the current digit needs to be represented with a letter
            {
                remainder_buffer += 55;
            }
            else //If the current digit can be represented with a numeric (0 through 9)
            {
                remainder_buffer += 48;
            }

            output = Character.toString((char) remainder_buffer) + output;

            int quotient_buffer = quotient;
            remainder_buffer = remainder;//quotient_buffer is needed because calculations need to be done
                                         //with the same 'quotient' number twice

            if (remainder != 0 || quotient != 0)
            {
                do {
                    quotient = quotient / new_base;
                    remainder = quotient_buffer % new_base;
                    remainder_buffer = remainder;

                    if (remainder > 9 && remainder < new_base) //If the current digit needs to be represented with a letter
                    {
                        remainder_buffer += 55; //This turns 'temp' into ASCII format
                    }
                    else //If the current digit can be represented with a numeric (0 through 9)
                    {
                        remainder_buffer += 48;
                    }

                    output = Character.toString((char) remainder_buffer) + output;

                    quotient_buffer = quotient;

                } while (quotient > 0);
            }

            remainder = quotient % new_base;

            if (remainder != 0) //If the remainder is not zero, but the quotient is
            {
                remainder = quotient % new_base;
                remainder_buffer = remainder;

                if (remainder > 9 && remainder < new_base) //If the current digit needs to be represented with a letter
                {
                    remainder_buffer += 55; //This turns 'temp' into ASCII format
                }
                else //If the current digit can be represented with a numeric (0 through 9)
                {
                    remainder_buffer += 48;
                }

                output = Character.toString((char) remainder_buffer) + output;
            }

        }

        if (isNegative)
        {
            output = "-" + output;
        }
        return output;

    }

}



