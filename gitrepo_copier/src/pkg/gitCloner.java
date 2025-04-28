/**
*
* @author Zeynep Sude Öncü - zey.su.oncu@gmail.com
* @since 02.04.2024-06.04.2024
* <p>
*  Girilen linkten git reposunu klonlayan sınıftır. Cloner methodu repoyu klonlayıp 
*  kodun bulunduğu dosyaya kopyalar ve kopyalanan dosya ismini döndürür.
* </p>
*/

package pkg;

import java.io.File;
import java.io.IOException;

public class gitCloner {
	private String dosyaismi="";
	private String dosya=System.getProperty("user.dir");
	private String Url;
	
	public gitCloner(String url)throws IOException, InterruptedException{
		Url=url;
	}
	
	public String cloner() throws IOException, InterruptedException
	{
		ProcessBuilder pb=new ProcessBuilder();
		pb.command("git","clone",Url);
		pb.directory(new File(dosya));
		Process process=pb.start();
		int exit=process.waitFor();
				for (int i = Url.length() - 1; i >= 0; i--) 
				{
		            char gosterge = Url.charAt(i);
		            if (gosterge == '/') {
		                break;
		        }
		            dosyaismi = gosterge + dosyaismi;
		        }

		        return dosyaismi;
		
	}
	
}
