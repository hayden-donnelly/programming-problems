import java.io.*;
import java.text.DecimalFormat;

public class StringMLB_donnellyh
{
    public static void main (String[] args) throws IOException
    {		
		// Init variables
		String output = "";
		int sum_at_bats = 0;
		int sum_singles = 0;
		int sum_doubles = 0;
		int sum_triples = 0;
		int sum_home_runs = 0;
		float big10_ba = 0.0f; 
		float big10_sa = 0.0f;
		DecimalFormat df = new DecimalFormat("#.000");
		BufferedReader input = new BufferedReader(new FileReader("data1.txt"));
		String s = input.readLine();
		output += s + "\n====================\n";
		
		// Parse input
		s = input.readLine();
		while(s != null)
		{
			String[] elements = s.split(" ");
			int at_bats = Integer.parseInt(elements[2]);
			int total_hits = Integer.parseInt(elements[4]);
			int doubles = Integer.parseInt(elements[5]);
			int triples = Integer.parseInt(elements[6]);
			int home_runs = Integer.parseInt(elements[7]);
			int singles = total_hits - (doubles + triples + home_runs);
			
			sum_at_bats += at_bats;
			sum_singles += singles;
			sum_doubles += doubles;
			sum_triples += triples;
			sum_home_runs += home_runs;
			
			float ba = (float)(singles + doubles + triples + home_runs) / (float)at_bats;
			float sa = (float)(singles + (2 * doubles) + (3 * triples) + (4 * home_runs)) / (float)at_bats;
			
			output += elements[0] + ": " + df.format(ba) + " " + df.format(sa) + "\n";
			s = input.readLine();
		}
		
		// Output
		big10_ba = (float)(sum_singles + sum_doubles + sum_triples + sum_home_runs) / (float)sum_at_bats;
		big10_sa = (float)(sum_singles + (2 * sum_doubles) + (3 * sum_triples) + (4 * sum_home_runs)) / (float)sum_at_bats;
		output += "====================\n";
		output += "Big 10 Avg: " + df.format(big10_ba) + " " + df.format(big10_sa) + "\n";
		System.out.print(output);
	}
}