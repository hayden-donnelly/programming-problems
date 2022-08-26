import java.io.*;
import java.util.HashMap;

public class StringDNA_donnellyh
{
    public static void main (String[] args) throws IOException
    {		
		// Init variables
		String dna = "AXYBBXYBABAABBXYXXYABBAXXYXABYYABXXABYYAB";
		String transcription, transcription_compliment = "";
		
		int promoter_id = dna.indexOf("BABAAB") + 6;
		int terminator_id = -1;
		
		HashMap<Character, Character> compliment_table = new HashMap<Character, Character>();
		compliment_table.put('A', 'B');
		compliment_table.put('B', 'A');
		compliment_table.put('X', 'Y');
		compliment_table.put('Y', 'X');
		
		// Find terminator id
		for(int k = 0; k <= dna.length() - 12; k++)
		{
			boolean terminator_found = true;
			for(int i = 0; i < 6; i++)
			{
				if(dna.charAt(k+i) != compliment_table.get(dna.charAt(k+11-i)))
				{
					terminator_found = false;
					break;
				}
			}
			if(terminator_found)
			{
				terminator_id = k;
				break;
			}
		}
		
		// Find transcription compliment
		transcription = dna.substring(promoter_id, terminator_id);
		for(int i = 0; i < transcription.length(); i++)
		{
			transcription_compliment += compliment_table.get(transcription.charAt(i));
		}
		
		//Final output
		System.out.println(transcription_compliment);
	}
}
