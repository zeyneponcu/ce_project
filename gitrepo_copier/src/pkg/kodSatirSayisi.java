/**
*
* @author Zeynep Sude Öncü - zey.su.oncu@gmail.com
* @since 05.04.2024-06.04.2024
* <p>
* Kod satır sayısını döndüren sınıftır. Sayıcı methodu boşluklar ve tek başına satır halindeki
* yorum satırları dışındaki kod satırı sayısını döndürür, javadoc sayısı mainde çıkartılır.
* </p>
*/

package pkg;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class kodSatirSayisi {
	private String kodlar="";
	private int kodSatir=0;
	private int javadoc=0;
	private String regex="^\\s*\\//.*$";
	private int yorum=0;
	
	public kodSatirSayisi(String kod){
		kodlar=kod;
	}
	
	public int sayici() {
		Pattern ptr=Pattern.compile(regex);
		String[] satirlar = kodlar.split("\n");
        for (String satir : satirlar) {
        	Matcher mtc=ptr.matcher(satir);
    		while(mtc.find()) {
    			yorum++;
    		}
        	if(!satir.trim().isEmpty()) {
        		kodSatir++;
        		
        	}
        }
		return kodSatir-yorum;
	}
	
}
