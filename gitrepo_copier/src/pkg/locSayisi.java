/**
*
* @author Zeynep Sude Öncü - zey.su.oncu@gmail.com
* @since 05.04.2024-06.04.2024
* <p>
* Kodun her şey dahil satır sayısını döndüren sınıftır.
* </p>
*/

package pkg;

public class locSayisi {
	private String kodlar="";
	private int loc=0;
	
	public locSayisi(String kod){
		kodlar=kod;
	}
	
	public int sayici() {
		String[] satirlar = kodlar.split("\n");
        for (String satir : satirlar) {
        	loc++;
        }
		return loc;
	}
}
