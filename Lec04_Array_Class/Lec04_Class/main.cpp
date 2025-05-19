//#include "Complex.h"
//#include "SportsCar.h"
//#include "SportsCar2.h"
#include "Music.h"

//void main()
//{
	//Complex a, b, c;
	//a.read( "A =");
	//b.read( "B =");
	//c.add(a, b);
	//a.print ("A = ");
	//b.print ("B = ");
	//c.print ("A+B =");

	//Car myCar;
	//Car momsCar(10, "K5", 2);
	//SportsCar mySecondCar

	//myCar.whereAmI();
	//momsCar.whereAmI();
	//myCar.changeGear(3);
	//momsCar.speedUp();
	//momsCar.display();
	//mySecondCar.bTurbo();

//}

int main()
{
	//music streaming�� ���� 
	MusicStreamingService my_service("spotify");
	my_service.addMusic("PolaroidLove", "ENHYPEN", "DIMESION", 2022);
	my_service.addMusic("CAKE", "ITZY", "ALBUM", 2023);
	
	//add by user
	//������ü���� ����� �Է� �ޱ� �׸��� �Է¹��� ���� ������ ������ü ��������� �ϳ��� ä��� ���������� ���� ��ü ���̼��� �� ���� ����Ʈ�� Ǫ�ù��ϱ�

//search muic by title 
	string music_title;
	cout << "Enter the Music Title: ";
	cin >> music_title;
	Music* result = my_service.searchByTitle(music_title);
	if (result != NULL) {
		cout << "Found:" << result->getTitle() << "by" << result->getArtist() << endl;
	}

	//search music by artist
	string artist_name;
	cout << "Enter the Artist Name: ";
	cin >> artist_name;
	vector<Music*> artist_result = my_service.searchByArtist(artist_name);
	if (!artist_result.empty()) {
		cout << "Found " << artist_result.size() << " song(s) by " << artist_name << ":\n";
		for (Music* music : artist_result) {
			cout << "- " << music->getTitle() << " (" << music->getAlbum() << ", " << music->getYear() << ")" << endl;
		}
	}
	else {
		cout << "No songs found by " << artist_name << "." << endl;
	}
	

}
