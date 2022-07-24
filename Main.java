import java.sql.SQLException;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) throws SQLException, ClassNotFoundException {
		Data db = new Data();
		db.openConnessione();
		
		boolean t = db.connessione();
		if (t) System.out.println("Connesso al Database");
		else System.out.println("non connesso");
		
		
		
		
		// faccio un try catch in modo che se ci fosse un errore me lo intercetterebbe dandomi un messaggio
       try { 
    	   
    	   System.out.println("QUALE OPERAZIONE DESIDERI SVOLGERE?");
    	   System.out.println("1) LOGIN");
    	   System.out.println("2) REGISTRAZIONE");
    	   
    	   Scanner scanner = new Scanner(System.in);
		   int opzione = scanner.nextInt();
    	   
    	   switch (opzione) {
    	     case 1 : //login
    	    	 System.out.println("Inserisci Username: ");
    	    	 String user = scanner.nextLine();
    	    	 System.out.println("Inserisci Password: ");
    	    	 String psw = scanner.nextLine();
    	    	 
    	    	 //Se il login va a buon fine va a scrivere Benvenuto NomeUtente
    	    	 if(db.login(user, psw)) {
    	    		 System.out.println("BENVENUTO" + db.getname(user));
    	    		 System.out.println("Lista degli utenti registrati: \n" +db.getUsers());
    	    	 }
    	    	 else System.out.println("I Dati inseriti non sono validi");
    	    	 
    	    	 
    	    	 break;
    	    	 
    	     case 2 : //registrazione
    	    	 System.out.println("BENVENUTO, inserisci qua il tuo Nome: ");
    	    	 String nome = scanner.nextLine();
    	    	 System.out.println("Dammi il tuo Username: ");
    	    	 String username = scanner.nextLine();
    	    	 System.out.println("Dammi la Password: ");
    	    	 String pass = scanner.nextLine();
    	    	 
    	    	 //apro la connessione così creo la tabella per contenere i dati
    	    	 db.openConnessione ();
    	    	 
    	    	 //inserisco i dati
    	    	 db.register(nome, username, pass);
    	    	 System.out.println("Sei stato registrato con successo");
    	    	 break;
    	    default:
    	    	System.out.println ("Opzione non in lista");
    	    	break;
    	    	 
    	   }
    	   
    	   System.exit(0);
    	   
       }
	
       catch(SQLException e) {
    	   System.out.println(e.getMessage());
       }

}
}
