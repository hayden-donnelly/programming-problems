import java.io.*;
import java.text.DecimalFormat;

public class WeightConversion_donnellyh
{
	public static void main(String[] args) throws IOException
	{
		boolean pounds_to_kilograms = false;
		DecimalFormat df = new DecimalFormat("0.0000");
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		int rows;
		int columns;
		String s;
		
		while(true)
		{
			System.out.print("To input in pounds, type \"p\". To input in kilograms, type \"k\": ");
			s = input.readLine();
			if(s.equals("p"))
			{
				pounds_to_kilograms = true;
				break;
			}
			else if(s.equals("k"))
			{
				pounds_to_kilograms = false;
				break;
			}
		}
		
		System.out.print("\n\n");
		
		// Row input
		while(true)
		{
			System.out.print("Enter number of rows of data (1-9): ");
			s = input.readLine();
			if(is_integer(s))
			{
				int buffer = Integer.parseInt(s);
				if(buffer >= 1 && buffer <= 9)
				{
					rows = buffer;
					break;
				}
				System.out.print("Invalid, rows must be in the range 1 - 9\n");
				continue;
			}
			System.out.print("Invalid, rows must be a number (integer), please try again\n");
		}
		
		System.out.print("\n\n");
		
		// Column input
		while(true)
		{
			System.out.print("Enter number of columns of data (1-9): ");
			s = input.readLine();
			if(is_integer(s))
			{
				int buffer = Integer.parseInt(s);
				if(buffer >= 1 && buffer <= 9)
				{
					columns = buffer;
					break;
				}
				System.out.print("Invalid, columns must be in the range 1 - 9\n");
				continue;
			}
			System.out.print("Invalid, columns must be a number (integer), please try again\n");
		}
		
		System.out.print("\n\n");
		double[][] weights = new double[rows][columns];
		double[][] weights_converted = new double[rows][columns];
		
		// Weight input
		for(int r = 0; r < rows; r++)
		{
			for(int c = 0; c < columns; c++)
			{
				while(true)
				{
					System.out.print("Enter weight for (" + (r+1) + ", " + (c+1) + "): ");
					s = input.readLine();
					if(is_double(s))
					{
						double buffer = Double.parseDouble(s);
						if(buffer >= 0)
						{
							weights[r][c] = buffer;
							break;
						}
						System.out.print("Invalid, weight must be non-negative\n");
						continue;
					}
					System.out.print("Invalid, weight must be a number\n");
				}
			}
		}
		
		// Convert weights, format and output
		// Repeated code but it's quicker
		if(pounds_to_kilograms)
		{
			for(int r = 0; r < rows; r++)
			{
				for(int c = 0; c < columns; c++)
				{
					weights_converted[r][c] = pound_to_kilogram(weights[r][c]);
				}
			}
			output_arrays(format_array(weights, df, "p"), format_array(weights_converted, df, "k"));
		}
		else
		{
			for(int r = 0; r < rows; r++)
			{
				for(int c = 0; c < columns; c++)
				{
					weights_converted[r][c] = kilogram_to_pound(weights[r][c]);
				}
			}
			output_arrays(format_array(weights, df, "k"), format_array(weights_converted, df, "p"));
		}
	}
	
    private static boolean is_integer(String s)
    {
        try
        {
            int num = Integer.parseInt(s);
            return true;
        }
        catch(Exception e)
        {
            return false;
        }
    }
	
    private static boolean is_double(String s)
    {
        try
        {
            double num = Double.parseDouble(s);
            return true;
        }
        catch(Exception e)
        {
            return false;
        }
    }
	
	private static double pound_to_kilogram(double pound_value)
	{
		return pound_value * 0.453592f;
	}
	
	private static double kilogram_to_pound(double kilogram_value)
	{
		return kilogram_value * 2.20462f;
	}
	
	// Weight type should be 'p' if pounds and 'k' if kilograms
	private static String[][] format_array(double[][] arr, DecimalFormat df, String weight_type)
	{
		String[][] formatted_arr = new String[arr.length+1][arr[0].length];
		for(int i= 0; i < arr.length; i++)
		{
			for(int k = 0; k < arr[i].length; k++)
			{
				formatted_arr[i][k] = df.format(arr[i][k]);
			}
		}
		formatted_arr[arr.length][0] = weight_type;
		return formatted_arr;
	}
	
	private static void output_arrays(String[][] original, String[][] converted)
	{
		boolean original_is_pounds = false;
		if(original[original.length-1][0].equals("p")) { original_is_pounds = true; }
		
		System.out.print("\n\nResults\n\n====================\n");
		
		if(original_is_pounds) { System.out.print("\nP\n"); }
		else { System.out.print("\nK\n"); }
		for(int i = 0; i < original.length-1; i++)
		{
			for(int k = 0; k < original[i].length; k++)
			{
				System.out.print(original[i][k] + " ");
			}
			System.out.print("\n");
		}
		
		if(original_is_pounds) { System.out.print("\nK\n"); }
		else { System.out.print("\nP\n"); }
		for(int i = 0; i < converted.length-1; i++)
		{
			for(int k = 0; k < converted[i].length; k++)
			{
				System.out.print(converted[i][k] + " ");
			}
			System.out.print("\n");
		}
	}
}