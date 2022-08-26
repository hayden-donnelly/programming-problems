import java.io.*;
import java.lang.Math; 

public class DataController_donnellyh
{
	public static void main(String[] args)
	{
		System.out.println("Welcome to the dataset program.\n");
		
		Data d1 = new Data();
		System.out.println("The description is: " + d1.description());
		System.out.println("The date created was: " + d1.date_created());
		System.out.println();
		
		float b[] = {10, 20, 31, 42.3f, 16.6f};
		Data d2 = new Data("Novel Dataset", "A random new dataset.", b, true, "December 2nd, 2020");
		System.out.println("The description is: " + d2.description());
		System.out.println("The date created was: " + d2.date_created());
		System.out.println("The mean is: " + d2.mean());
		System.out.println("The standard deviation is: " +  d2.standard_deviation());
		System.out.println("The min value is: " + d2.min());
		System.out.println("The max value is: " + d2.max());
		System.out.println();
		
		float c[] = {12, 90, 31, 47.3f, 19.6f};
		Data d3 = new Data("MNIST", "The MNIST dataset.", c, false, "October 5th, 1998");
		System.out.println("The description is: " + d3.description());
		System.out.println("The date created was: " + d3.date_created());
		System.out.println("The mean is: " + d3.mean());
		d3.set_value(3, 500.34f);
		System.out.println("The mean is: " + d3.mean());
		System.out.println("The standard deviation is: " + d3.standard_deviation());
		System.out.println("The min value is: " + d3.min());
		System.out.println("The max value is: " + d3.max());
		System.out.println();
	}
}

class Data
{
	private String set_name;
	private String description;
	private String creation_date;
	private float[] data_points;
	private boolean immutable_data;
	
	public Data()
	{
		set_name = "Datset";
		description = "Default dataset.";
		data_points = new float[0];
		immutable_data = false;
		creation_date = "date was not specified";
	}
	
	public Data(String name, String desc, float[] data, boolean immutable, String date)
	{
		set_name = name;
		description = desc;
		data_points = data;
		immutable_data = immutable;
		creation_date = date;
	}
	
	public float mean()
	{
		float summation = 0.0f;
		for(int i = 0; i < data_points.length; i++)
		{
			summation += data_points[i];
		}
		return summation / data_points.length;
	}
	
	public float standard_deviation()
	{
		float std_mean = mean();
		float sds_summation = 0.0f;
		for(int i = 0; i < data_points.length; i++)
		{
			sds_summation += Math.pow(data_points[i]-std_mean, 2);
		}
		return (float)Math.sqrt(sds_summation/data_points.length);
	}
	
	public float min()
	{
		float min = 0.0f;
		if(data_points.length >= 1)
		{
			min = data_points[0];
			for(int i = 1; i < data_points.length; i++)
			{
				if(data_points[i] < min)
				{
					min = data_points[i];
				}
			}
		}
		return min;
	}
	
	public float max()
	{
		float max = 0.0f;
		if(data_points.length >= 1)
		{
			max = data_points[0];
			for(int i = 1; i < data_points.length; i++)
			{
				if(data_points[i] > max)
				{
					max = data_points[i];
				}
			}
		}
		return max;
	}
	
	public void set_value(int i, float val)
	{
		if(!immutable_data && i >=0 && i < data_points.length)
		{
			data_points[i] = val;
		}
	}
	
	public String date_created()
	{
		return creation_date;
	}
	
	public String description()
	{
		return description;
	}
}

