public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        { }

        private DataTable GetEmployeeData()
        {
            DataTable dt = new DataTable();
            dt.Columns.Add("Id");
            dt.Columns.Add("Name");
            dt.Columns.Add("Gender");

            dt.Rows.Add(txtId1.Text, txtName1.Text, txtGender1.Text);
            dt.Rows.Add(txtId2.Text, txtName2.Text, txtGender2.Text);
            dt.Rows.Add(txtId3.Text, txtName3.Text, txtGender3.Text);
            dt.Rows.Add(txtId4.Text, txtName4.Text, txtGender4.Text);
            dt.Rows.Add(txtId5.Text, txtName5.Text, txtGender5.Text);

            return dt;
        }

        protected void btnInsert_Click(object sender, EventArgs e)
        {
            string cs = ConfigurationManager.ConnectionStrings["DBCS"].ConnectionString;
            using (SqlConnection con = new SqlConnection(cs))
            {
                SqlCommand cmd = new SqlCommand("spInsertEmployees", con);
                cmd.CommandType = CommandType.StoredProcedure;

                SqlParameter paramTVP = new SqlParameter()
                {
                    ParameterName = "@EmpTableType",
                    Value = GetEmployeeData()
                };
                cmd.Parameters.Add(paramTVP);

                con.Open();
                cmd.ExecuteNonQuery();
                con.Close();
            }
        }

        protected void btnFillDummyData_Click(object sender, EventArgs e)
        {
            txtId1.Text = "1";
            txtId2.Text = "2";
            txtId3.Text = "3";
            txtId4.Text = "4";
            txtId5.Text = "5";

            txtName1.Text = "John";
            txtName2.Text = "Mike";
            txtName3.Text = "Sara";
            txtName4.Text = "Pam";
            txtName5.Text = "Todd";

            txtGender1.Text = "Male";
            txtGender2.Text = "Male";
            txtGender3.Text = "Female";
            txtGender4.Text = "Female";
            txtGender5.Text = "Male";
        }
    }