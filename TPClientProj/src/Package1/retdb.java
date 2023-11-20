package Package1;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class retdb {
    void loadDriver() throws ClassNotFoundException {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
        } catch (ClassNotFoundException e) {
            throw new ClassNotFoundException("Pilote JDBC introuvable !", e);
        }
    }

    final String url = "jdbc:mysql://localhost:3306/dbtest";

    public void listServices() throws SQLException {
        Connection conn = null;
        Statement st = null;
        ResultSet rs = null;

        try {
            conn = DriverManager.getConnection(url, "root", "root");
            st = conn.createStatement();
            String query = "SELECT number, name FROM services WHERE id=2";
            rs = st.executeQuery(query);

            while (rs.next()) {
                System.out.println(rs.getString("number") + " " + rs.getString("name"));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            try {
                if (rs != null) {
                    rs.close();
                }
                if (st != null) {
                    st.close();
                }
                if (conn != null) {
                    conn.close();
                }
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
    }

    public static void main(String[] args) {
        retdb test = new retdb();
        try {
            test.loadDriver();
            test.listServices();
        } catch (ClassNotFoundException e) {
            System.err.println("Pilote JDBC introuvable !");
        } catch (SQLException e) {
            System.out.println("SQLException: " + e.getMessage());
            e.printStackTrace();
        }
    }
}
