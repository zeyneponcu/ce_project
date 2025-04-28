/**
*
* @author Zeynep Sude Öncü - zey.su.oncu@gmail.com
* @since 04.04.2024-06.04.2024
* <p>
*  Yorum sayısını bulan sınıftır. sayıcı methodu regex kullanarak '//' yorum 
*  satırı başlangıçlarını arar ve çoklu yorum satırı halindeki tekli yorum
*   satırlarını da bulup toplamını döndürür.
* </p>
*/

package pkg;

import java.util.regex.Matcher;
import java.util.regex.Pattern;


public class yorumSayisi {
	private String kodlar="";
	private String regex="//.*";
	private int yorum=0;
	private Boolean flag=false;
	
	public yorumSayisi(String kod){
		kodlar=kod;
	}
	
	public int sayici() {
		int teksatirliys=0,kontrol1=0,kontrol2=0;
		Pattern ptr=Pattern.compile(regex);
		Matcher mtc=ptr.matcher(kodlar);
		while(mtc.find()) {
			yorum++;
		}
		String[] satirlar = kodlar.split("\n");
        for (String satir : satirlar) {
        	kontrol1++;
        	if(flag) {
        		teksatirliys++;
        		flag=false;
        	}
        	if(satir.contains("/*")) {
        		kontrol2=kontrol1;
        	}
        	if(satir.contains("*/")) {
        		if(kontrol1-kontrol2==2) {
        			flag=true;
        		}
        	}
        	
        }
		return yorum+teksatirliys;
	}
}
