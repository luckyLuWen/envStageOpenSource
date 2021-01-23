package cn.envStage.domain;

import java.io.Serializable;

/**
 * 用户实体类
 */
public class User implements Serializable {
    private int userID;//用户id
    private String userName;//用户名，账号
    private String gender;
    private String role;
    private String userAccount;
    private String userPassword;
    private String telephone;
    private String email;

    public User(){}

    public User(int userID, String userName, String gender, String role, String userAccount, String userPassword, String telephone, String email) {
        this.userID = userID;
        this.userName = userName;
        this.gender = gender;
        this.role = role;
        this.userAccount = userAccount;
        this.userPassword = userPassword;
        this.telephone = telephone;
        this.email = email;
    }

    public int getUserID() {
        return userID;
    }

    public void setUserID(int userID) {
        this.userID = userID;
    }

    public String getUserName() {
        return userName;
    }

    public void setUserName(String userName) {
        this.userName = userName;
    }

    public String getGender() {
        return gender;
    }

    public void setGender(String gender) {
        this.gender = gender;
    }

    public String getRole() {
        return role;
    }

    public void setRole(String role) {
        this.role = role;
    }

    public String getUserAccount() {
        return userAccount;
    }

    public void setUserAccount(String userAccount) {
        this.userAccount = userAccount;
    }

    public String getUserPassword() {
        return userPassword;
    }

    public void setUserPassword(String userPassword) {
        this.userPassword = userPassword;
    }

    public String getTelephone() {
        return telephone;
    }

    public void setTelephone(String telephone) {
        this.telephone = telephone;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    @Override
    public String toString() {
        return "User{" +
                "userID=" + userID +
                ", userName='" + userName + '\'' +
                ", gender='" + gender + '\'' +
                ", role='" + role + '\'' +
                ", userAccount='" + userAccount + '\'' +
                ", userPassword='" + userPassword + '\'' +
                ", telephone='" + telephone + '\'' +
                ", email='" + email + '\'' +
                '}';
    }
}
