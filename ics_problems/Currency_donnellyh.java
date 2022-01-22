import java.io.*;
import java.text.DecimalFormat;
import java.util.HashMap;

public class Currency_donnellyh
{
    public static void main (String[] args) throws IOException
    {
		// Init variables 
		int from_code;
		int to_code;
		double ammount;
		String in;
		DecimalFormat df = new DecimalFormat("#0.00");
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		
		// Select row with from_code and column with to_code.
		// Diagonal is the identity.
		double[] exchange_rates = { 1f, 0.748450f, 0.673275f, 54.9024f,			// CAD
									1.33611f, 1f, 0.899542f, 73.3484f,			// USD
									1.48560f, 1.11184f, 1f, 81.5580f, 			// EUR
									0.0182152f, 0.0136325f, 0.0122620f, 1f };	// INR
		
		// Table to convert numeric from/to codes into a proper currency code.
		HashMap<Integer, String> code_table = new HashMap<Integer, String>();
		code_table.put(1, "CAD");
		code_table.put(2, "USD");
		code_table.put(3, "EUR");
		code_table.put(4, "INR");
		
		while(true)
		{
			// Reset variables
			from_code = 0;
			to_code = 0;
			ammount = 0.0f;
			
			// Welcome message/country codes
			System.out.println("Welcome to the Currency Exchange Program!\n");
			System.out.println("Country Codes");
			System.out.println("===========");
			System.out.println("1: CAD");
			System.out.println("2: USD");
			System.out.println("3: EUR");
			System.out.println("4: INR");
			System.out.println("5: QUIT");
			System.out.println("===========\n");
			
			// FROM code input
			while(true)
			{
				System.out.print("Please enter the FROM code: ");
				in = input.readLine();
				from_code = Integer.parseInt(in);
				if(from_code >= 1 && from_code <= 5) 
				{ 
					break; 
				}
				else
				{
					System.out.println("^^^Please enter a valid code^^^");
				}
			}		
			if(from_code == 5)
			{
				break;
			}
			
			// TO code input
			while(true)
			{
				System.out.print("Please enter the TO code: ");
				in = input.readLine();
				to_code = Integer.parseInt(in);
				if(to_code >= 1 && to_code <= 5) 
				{ 
					break; 
				}
				else
				{
					System.out.println("^^^Please enter a valid code^^^");
				}
			}
			if(to_code == 5)
			{
				break;
			}
			
			// Exchange ammount input
			while(true)
			{
				System.out.print("Please enter the amount of money that you want exchanged: ");
				in = input.readLine();
				ammount = Double.parseDouble(in);
				if(ammount >= 0) 
				{ 
					break; 
				}
				else
				{
					System.out.println("^^^Please enter a valid ammount^^^");
				}
			}
			
			// Final output
			Double exchanged_ammount = ammount * exchange_rates[4 * (from_code - 1) + (to_code - 1)];
			System.out.println(code_table.get(from_code) + " " + df.format(ammount) + " = " + df.format(exchanged_ammount) + " " + code_table.get(to_code) + "\n");
		}
	}
}