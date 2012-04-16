//Implement an algorithm to determine if a string has all unique characters  What if you 
//can not use additional data structures

//Author: Panda

public class duplicatedCharInString {

	private boolean[] mask;
	
	public boolean ifDuplicated (char[] s)
	{
		boolean duplicate = false;
		mask = new boolean[256];
		
		for(int i =0 ; i < s.length; ++i)
		{
			int ascii = s[i];
			if(mask[ascii] == false)
			{
				mask[ascii] = true;
			}else
			{
				duplicate = true;
			}
		}
		return duplicate;
	}
	
	
	public static void main(String[] args) {
		
		duplicatedCharInString test = new duplicatedCharInString();
		String s1 = "YLovesZ";
		String s2 = "YYLovesParty";
		
		//this test should return false
		System.out.println(test.ifDuplicated(s1.toCharArray()));
		
		//this test should return true
		System.out.println(test.ifDuplicated(s2.toCharArray()));
	}

}
