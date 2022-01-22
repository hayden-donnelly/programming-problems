import java.io.*;

public class StringDictionary_donnellyh
{
	public static void main (String[] args) throws IOException
	{
		String the_alphabet = "abcdefghijklmnopqrstuvwxyz";
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		
		System.out.println("Welcome to the \"Proper English\" program!\n");
		
		while(true)
		{	
			System.out.print("\nInput word: ");
			String s = input.readLine().toLowerCase();
			if(s.equals("quit"))
			{
				break;
			}
			String[] words = s.split(" ");
			
			for(int k = 0; k < words.length; k++)
			{
				for(int i = words[k].length()-2; i >= 1; i--)
				{
					String x = words[k].substring(i, i+1).toLowerCase();
					String y = words[k].substring(i+1, i+2).toLowerCase();
					if(the_alphabet.indexOf(x) >= 0 && the_alphabet.indexOf(y) >= 0)
					{
						if(x.equals("o") && y.equals("r"))
						{
							words[k] = words[k].substring(0, i) + "our" + words[k].substring(i+2);
						}
						else
						{
							break;
						}
					}
				}
			}
			
			String test = "";
			System.out.println("New word: " + test.join(" ", words) + "\n");
		}
		
		System.out.println("\n\nThank you for using the \"Proper English\" program!\n");
	}
}