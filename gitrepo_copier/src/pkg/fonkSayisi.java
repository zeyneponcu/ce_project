/**
*
* @author Zeynep Sude Öncü - zey.su.oncu@gmail.com
* @since 05.04.2024-06.04.2024
* <p>
* Fonksiyon sayısını döndüren sınıftır. Sayıcı methodu, başında private veya public
* bulunan ardından boşluklar ve harfler olan ve sonunda ; olmayan satırları bularak ve 
* class tanımının bulunduğu satırı çıkararak fonksiyon sayısının döndürür.
* </p>
*/

package pkg;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class fonkSayisi {
	private String kodlar="";
	private int fonk=0;
	private String regex="(private|public)\\s+\\w+\\s*[^;]+$";
	
	public fonkSayisi(String kod){
		kodlar=kod;
	}
	
	public int sayici() {
		Pattern ptr=Pattern.compile(regex);
		String[] satirlar = kodlar.split("\n");
        for (String satir : satirlar) {
        	Matcher mtc=ptr.matcher(satir);
    		while(mtc.find()) {
    			fonk++;
    		}
        }
		return fonk-1;
	}
}
