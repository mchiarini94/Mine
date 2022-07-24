import java.sql.SQLException; //per gestire le eccezzioni
import java.sql.Statement;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;


public class Data {
	
	private String url;
	private Connection conn;
	
	
	//costruttore
	public Data () throws ClassNotFoundException  {
		Class.forName("com.mysql.cj.jdbc.Driver");
		this.url = "jdbc:mysql://localhost:3306/java";
		
		
		this.conn = null;
	}
	
	public void openConnessione () throws SQLException{
		//Class.forName("com.mysql.Driver");
		this.conn = DriverManager.getConnection(this.url,"pma","primaguerra15"); //prima si connette
		
		createTable();// poi crea la tabella 
	}
	
	public boolean connessione () {
		if (this.conn != null) return true;
		else return false;
	}
	
	//metodo che dice se il login è andato con successo o meno
	public boolean login (String user, String psw) throws SQLException{
		PreparedStatement pst = this.conn.prepareStatement("SELECT id FROM java WHERE username = ? and psw = ?");
		//riepmio i campi
		pst.setString(1, user);
		pst.setString(2, psw);
		ResultSet rs = pst.executeQuery(); //tutti i risultati della Query verranno inseriti in rs
		//rs cerca se c'è un riscontro positivo nella Query
		return rs.next(); 
	}
	
	//Fa comparire il nome dell'utente quando si logga 
	public String getname(String user ) throws SQLException{
		PreparedStatement pst = this.conn.prepareStatement("SELECT id FROM java WHERE username = ?");
		pst.setString(1, user);
		ResultSet rs = pst.executeQuery();
		rs.next();//per fare andare avanti il cursore
		return rs.getString("name"); // se non trova corrispondenze ritorna NULL
	}
	
	//ritorna lista di tutti gli utenti
	public String getUsers() throws SQLException {
		Statement st = this.conn.createStatement();
		ResultSet rs = st.executeQuery("select * from java");
		String result ="";
		while (rs.next()) { //itera finchè c'è un successivo
			result += rs.getString("username")+">" +rs.getString("password")+"\n";
			} //prende i nomi e le password
		return result;
	}
	
	
	
	
	public void closeConnessione () throws SQLException {
		this.conn.close();
	}
	
	//riempio i campi della tabella
	public void register(String nome, String username, String psw) throws SQLException {
		//imposto il comando con un preparedStatement che mi permette di eseguire più volte la Query
		PreparedStatement pst = this.conn.prepareStatement ( 
				"INSERT INTO dado (nome, username, psw)" +"VALUES(?,?,?)"); 
		// i punti di domanda sono una sorta di controllo, ossia vado a riempirli manualmente
		//fossero state variabili avrei avuto la possibilità di venire hackerato con inserimento
		//di 1 == 1 che è sempre vero
		
		//inserisco i dati manualmente con setString
		pst.setString(1, nome); //1 perchè lo 0 è un parametro autoincrement
		pst.setString(2,username);
		pst.setString(2, psw);
		pst.executeUpdate(); // in questo modo faccio eseguire il comando
	}
	
	private void createTable() throws SQLException{ //throws gestisce le eventuali eccezzioni
		Statement st = this.conn.createStatement();
		st.execute ("CREATE TABLE dado  ("
				+ "id int PRIMARY KEY AUTO_INCREMENT," 
				+ "nome VARCHAR (25)"
				+ "username VARCHAR (25),"
				+ "psw VARCHAR(25),"
				+ ")") ;
		//dentro allo Statement metto il comando da eseguire
		
	}
	

}
