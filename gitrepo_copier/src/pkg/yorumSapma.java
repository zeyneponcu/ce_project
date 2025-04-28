/**
*
* @author Zeynep Sude Öncü - zey.su.oncu@gmail.com
* @since 06.04.2024-06.04.2024
* <p>
* Ödevde istenen sapma yüzdesini döndüren sınıftır. Hesaplayıcı methodu cast yaparak float 
* sayılar üzerinden işlem yapar ve float sayıyı döndürür. Sapma yüzdesinin istenen halini
* elde etmek için mainde decimal format sınıfından yararlanarak yuvarlama yapılır.
* </p>
*/

package pkg;

public class yorumSapma {
	private float YH=0;
	private float YG=0;
	private float ysYüzde=0;
	
	public yorumSapma(){
	
	}
	
	public float hesaplayici (int javadoc,int yorum,int kod,int fonk) {
		YG=(float)((float)(javadoc + yorum)*0.8/fonk);
		YH=(float) ((float)((float)kod/(float)fonk)*0.3);
		ysYüzde=(100*YG)/YH-100;
		
		return ysYüzde;
	}
}
