import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach

public class UrlValidatorTest extends TestCase {

   public UrlValidatorTest(String testName) {
      super(testName);
   }
   
   public void ourassertFalse(String testURL, String testName) {
	   
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   try{
		  assertFalse(urlVal.isValid(testURL)); 
	   }catch(AssertionError e) {
		   System.out.println(" 	 (Expected Invalid) URL: " + testURL);
	   }catch(Throwable t) {
		   //System.out.println("	 (Java Error(Invalid)) URL: " + testURL);
	   }
   }
 
   public void ourassertTrue(String testURL, String testName) {
	   
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   try{
		  assertTrue(urlVal.isValid(testURL)); 
	   }catch(AssertionError e) {
		   System.out.println(" 	 (Expected Valid) URL: " + testURL);
	   }catch(Throwable t) {
		   //System.out.println("	 (Java Error(Valid)) URL: " + testURL);
	   }
   }
   
   
   
   //Manual Test
   public void testManualTest()
   {
	   		System.out.println("Running Manual Tests: ");
	   		
	       //testing some tlds
	       ourassertTrue("http://corndog.io/", "Manual");//copied from browser
	       ourassertFalse("http://corndog.icmb/", "Manual"); //.icbm
	       ourassertTrue("https://www.nytimes.com/", "Manual"); //copied from browser
	       ourassertFalse("https://www.nytimes.comunist/", "Manual"); //copied from browser
	       ourassertTrue("https://oregonstate.edu/", "Manual");
	       ourassertFalse("https://oregonstate.udu/", "Manual");
	       
	       //testing some irregular characters
	       ourassertTrue("http://corndog.io/" , "Manual");//copied from browser
	       ourassertFalse("http://cÎ©rndog.icmb/", "Manual"); //.icbm
	       ourassertTrue("https://www.nytimes.com/", "Manual"); //copied from browser
	       ourassertFalse("https://www.nytimes.cÎ©m/", "Manual"); //copied from browser
	       ourassertTrue("https://oregonstate.edu/" , "Manual");
	       ourassertFalse("https://Î©regonstate.edu/","Manual");
   }
   
   //Programming Based Test
   public void testProgramTest() 
   {
	   System.out.println("Running Programming-Authority Tests: ");
	   //Unit Test: Authority (know valid scheme "http://" + authority
	   ourassertTrue("http://oregonstate.edu", "Programming-Authority");
	   ourassertTrue("http://www.amazon.com", "Programming-Authority");
	   ourassertTrue("http://123.com", "Programming-Authority");
	   ourassertTrue("http://amazon.com", "Programming-Authority");
	   ourassertTrue("http://www.amazon.uk", "Programming-Authority");
	   
	   ourassertFalse("http://", "Programming-Authority");
	   ourassertFalse("http://.www", "Programming-Authority");
	   ourassertFalse("http://www", "Programming-Authority");
	   ourassertFalse("http://www.", "Programming-Authority");
	   //Testing these authority fail with invalid scheme
	   ourassertFalse("://", "Programming-Authority");
	   ourassertFalse("://.www", "Programming-Authority");
	   ourassertFalse("://www", "Programming-Authority");
	   ourassertFalse("://www.", "Programming-Authority");
	   
	   System.out.println("Running Programming-Scheme Tests: ");
	   //Unit Test: Scheme (scheme + know valid authority "oregonstate.edu")
	   ourassertTrue("oregonstate.edu", "Programming-Scheme");
	   ourassertTrue("http://oregonstate.edu", "Programming-Scheme");
	   ourassertTrue("https://oregonstate.edu", "Programming-Scheme");
	   ourassertTrue("ftp://oregonstate.edu", "Programming-Scheme");
	   ourassertTrue("h3t://oregonstate.edu", "Programming-Scheme");
	  
	   ourassertFalse("://oregonstate.edu", "Programming-Scheme");
	   ourassertFalse("http/oregonstate.edu", "Programming-Scheme");
	   ourassertFalse("http:oregonstate.edu", "Programming-Scheme");
	   ourassertFalse("3http://oregonstate.edu", "Programming-Scheme");	
	   
	   System.out.println("Running Programming-Path Tests: ");
	   //Unit Test: Path (know valid scheme + authority "http://oregonstate.edu" + path)
       ourassertTrue("http://oregonstate.edu/","Programming-Path"); 
       ourassertTrue("http://oregonstate.edu/about","Programming-Path");
       ourassertTrue("http://oregonstate.edu/michaelpatson", "Programming-Path");
       ourassertTrue("http://oregonstate.edu/about/about","Programming-Path");
       ourassertTrue("http://oregonstate.edu/about/","Programming-Path");
       
       ourassertFalse("http://oregonstate.edu//..","Programming-Path");
       ourassertFalse("http://oregonstate.edu/..//file","Programming-Path");
       ourassertFalse("http://oregonstate.edu/../","Programming-Path");
       ourassertFalse("http://oregonstate.edu/about//about","Programming-Path");
       
       System.out.println("Running Programming-Port Tests: ");
       //Unit Test: Port (know valid scheme + authority + path "http://oregonstate.edu/about" + port)
       ourassertTrue("http://oregonstate.edu/about:","Programming-Port");
       ourassertTrue("http://oregonstate.edu/about:22","Programming-Port");
       ourassertTrue("http://oregonstate.edu/about:62341","Programming-Port");

	   ourassertFalse("http://oregonstate.edu/about:100000","Programming-Port");
	   ourassertFalse("http://oregonstate.edu/about:65536","Programming-Port");
	   ourassertFalse("http://oregonstate.edu/about:-12","Programming-Port");
	   ourassertFalse("http://oregonstate.edu/about:abc","Programming-Port");
	   //Testing these fail with an invalid path
	   ourassertFalse("http://oregonstate.edu/../:-12","Programming-Port");
	   ourassertFalse("http://oregonstate.edu/../:abc","Programming-Port");
   }
   
  //Random Tests
   public void testRandomValidTest()
   {
	   	//Partition: Scheme
	   		String testSchemePartition[] = new String[1];
	   		
	   		//Unit Test Passed
	   			//Default Scheme(all letters)://
	   			testSchemePartition[0] = "http://";
	   		//Java Error	
	   			//testSchemePartition[4] = "https://";
	   			//testSchemePartition[6] = "ftp://";
	   			//Number/Letter Mix
	   			//testSchemePartition[8] = "h3t://";

	   	//Partition: Authority
	   		String testAuthorityPartition[] = new String[5];
	   	
	   		//Unit Test Passed
	   			//Normal www.letters.com
	   			testAuthorityPartition[0] = "www.amazon.com";
	   			//No www.
	   			testAuthorityPartition[1] = "amazon.com";
	   			//Other country
	   			testAuthorityPartition[2] = "www.amazon.uk";
	   			//numbers.com
	   			testAuthorityPartition[3] = "123.com";
	   			//Letters.edu
	   			testAuthorityPartition[4] = "oregonstate.edu";
	   		
	   			
	   	//Partition: Port
	   		String testPortPartition[] = new String[3];
	   	
	   		//Unit Test Passed
	   			//Empty 
	   			testPortPartition[0] = ":";
	   			//Only Numbers
	   			testPortPartition[1] = ":22";
	   			testPortPartition[2] = ":62341";

	   			
	   //Partition: Path
	   		String testPathPartition[] = new String[3];
	   	
	   		//Unit Test Passed
   				//Empty 
   				testPathPartition[0] = "/";
   				// /word
   				testPathPartition[1] = "/michaelpatson";
   				testPathPartition[2] = "/about";

   		
   				
   				
   		System.out.println("Running Random Valid Tests: ");
   				
   		//Randomize URL
   		for(int i = 0; i < 100; i++)
   		{
   			int scheme = (int)(java.lang.Math.random()* 1);
   			int authority = (int)(Math.random()*5);
   			int port = (int)(Math.random()*3);
   			int path = (int)(Math.random()*3);
   			String url = testSchemePartition[scheme] + testAuthorityPartition[authority] + testPathPartition[path] + testPortPartition[port];

   			ourassertTrue(url, "Random");
   		}		
}
   public void testRandomInvalidTest()
   {
	   	//Partition: Scheme
	   		String testSchemePartition[] = new String[4];
	   		//Unit Test Passed
	   			//No letters
	   			testSchemePartition[0] = "://";
	   			//Missing Part of ://
	   			testSchemePartition[1] = "http/";
	   			testSchemePartition[2] = "http:";
	   			//Begin with number
	   			testSchemePartition[3] = "3http://";
	   	
	   	//Partition: Authority
	   		String testAuthorityPartition[] = new String[4];
	   		//None passed the unit test when used with a valid scheme
	   		//But the unit test was passed with an invalid scheme
	   			//Empty
	   			testAuthorityPartition[0] = "";
	   			// .letters
	   			testAuthorityPartition[1] = ".www";
	   			// only letters
	   			testAuthorityPartition[2] = "www";
	   			//letters.
	   			testAuthorityPartition[3] = "www.";
	   			
	   	//Partition: Port		
	   		String testPortPartition[] = new String[2];
	   		//None passed the unit test when used with a valid path
	   		//But the unit test was passed with an invalid path
	   			//Negative Number
	   			testPortPartition[0] = ":-12";
	   			//Letters
	   			testPortPartition[1] = ":abc";
	   			
	   //Partition: Path
	   		String testPathPartition[] = new String[4];
   			//Unit Test Passed
   				//Extra . or /
   				testPathPartition[0] = "/..//file";
   				testPathPartition[1] = "/about//about";
   				testPathPartition[2] = "//..";
   				testPathPartition[3] = "/../";
   				
   		System.out.println("Running Random Invalid Tests: ");
   				
   		//Randomize URL
   		for(int i = 0; i < 100; i++)
   		{
   			int scheme = (int)(java.lang.Math.random()* 4);
   			int authority = (int)(Math.random()*4);
   			int port = (int)(Math.random()*2);
   			int path = (int)(Math.random()*4);
   			String url = testSchemePartition[scheme] + testAuthorityPartition[authority] + testPathPartition[path] + testPortPartition[port];

   			ourassertFalse(url, "random");
   		}		

   }
   public void testRandomMixedTest()
   {
   		   	//Partition: Scheme
	   		String testSchemePartition[] = new String[8];
	   		
	   		//Valid
	   			//Default Scheme(all letters)://
	   			testSchemePartition[0] = "http://";
	   			testSchemePartition[2] = "http://";
	   			testSchemePartition[4] = "http://";
	   			testSchemePartition[6] = "http://";

	   		//Invalid
	   			//No letters
	   			testSchemePartition[1] = "://";
	   			//Missing Part of ://
	   			testSchemePartition[3] = "http/";
	   			testSchemePartition[5] = "http:";
	   			//Begin with number
	   			testSchemePartition[7] = "3http://";

	   		//Partition: Authority
	   		String testAuthorityPartition[] = new String[9];
	   	
	   		//Valid
	   			//Normal www.letters.com
	   			testAuthorityPartition[0] = "www.amazon.com";
	   			//No www.
	   			testAuthorityPartition[2] = "amazon.com";
	   			//Other country
	   			testAuthorityPartition[4] = "www.amazon.uk";
	   			//numbers.com
	   			testAuthorityPartition[6] = "123.com";
	   			//Letters.edu
	   			testAuthorityPartition[8] = "oregonstate.edu";

	   		//Invalid
	   		//None passed the unit test when used with a valid scheme
	   		//But the unit test was passed with an invalid scheme
	   			//Empty
	   			testAuthorityPartition[1] = "";
	   			// .letters
	   			testAuthorityPartition[3] = ".www";
	   			// only letters
	   			testAuthorityPartition[5] = "www";
	   			//letters.
	   			testAuthorityPartition[7] = "www.";

	  	   	//Partition: Port
	   		String testPortPartition[] = new String[5];
	   	
	   		//Valid
	   			//Empty 
	   			testPortPartition[0] = ":";
	   			//Only Numbers
	   			testPortPartition[2] = ":22";
	   			testPortPartition[4] = ":62341";

	   		//Invalid
	   		//None passed the unit test when used with a valid path
	   		//But the unit test was passed with an invalid path
	   			//Negative Number
	   			testPortPartition[1] = ":-12";
	   			//Letters
	   			testPortPartition[3] = ":abc";

	   			
	   		//Partition: Path
	   		String testPathPartition[] = new String[8];
	   	
	   		//Valid
   				//Empty 
   				testPathPartition[0] = "/";
   				// /word
   				testPathPartition[2] = "/michaelpatson";
   				testPathPartition[4] = "/about";
   				testPathPartition[6] = "/";
   			
   			//Invalid
   				//Extra . or /
   				testPathPartition[1] = "/..//file";
   				testPathPartition[3] = "/about//about";
   				testPathPartition[5] = "//..";
   				testPathPartition[7] = "/../";

     		System.out.println("Running Random Mixed Tests: ");

     	//Randomize URL
   		for(int i = 0; i < 100; i++)
   		{
   			int scheme = (int)(java.lang.Math.random()* 8);
   			int authority = (int)(Math.random()*9);
   			int port = (int)(Math.random()*5);
   			int path = (int)(Math.random()*8);
   			String url = testSchemePartition[scheme] + testAuthorityPartition[authority] + testPathPartition[path] + testPortPartition[port];
   			boolean result = true;

   			if(scheme % 2 > 0){
   				result = false;
   			}
   			if(authority % 2 > 0){
   				result = false;
   			}
   			if(port % 2 > 0){
   				result = false;
   			}
   			if(path % 2 > 0){
   				result = false;
   			}

   			if(result == true){
   				ourassertTrue(url, "Random");
   			}
   			else{
   				ourassertFalse(url, "Random");
   			}
   			
   		}		

   }

}
