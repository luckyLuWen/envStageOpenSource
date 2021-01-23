package cn.envStage.dao.impl;

import cn.envStage.dao.UserDao;
import cn.envStage.domain.User;
import cn.envStage.util.JDBCUtils;
import org.springframework.jdbc.core.BeanPropertyRowMapper;
import org.springframework.jdbc.core.JdbcTemplate;

public class UserDaoImpl implements UserDao {

    private JdbcTemplate template = new JdbcTemplate(JDBCUtils.getDataSource());

//    @Override
//    public User findByUsername(String username) {
//        User user = null;
//        try {
//            //1.定义sql
//            String sql = "select * from tab_user where username = ?";
//            //2.执行sql
//            user = template.queryForObject(sql, new BeanPropertyRowMapper<User>(User.class), username);
//        } catch (Exception e) {
//
//        }
//
//        return user;
//    }
//
//    @Override
//    public void save(User user) {
//        //1.定义sql
//        String sql = "insert into tab_user(username,password,name,birthday,sex,telephone,email,status,code) values(?,?,?,?,?,?,?,?,?)";
//        //2.执行sql
//
//        template.update(sql,user.getUsername(),
//                    user.getPassword(),
//                user.getName(),
//                user.getBirthday(),
//                user.getSex(),
//                user.getTelephone(),
//                user.getEmail(),
//                user.getStatus(),
//                user.getCode()
//                );
//    }


    /**
     * 根据用户名和密码查询的方法
     * @param username
     * @param password
     * @return
     */
    @Override
    public User findByUsernameAndPassword(String userAccount, String userPassword, String role) {
        User user = null;
        try {
            //1.定义sql
            String sql = "select * from user where userAccount = ? and userPassword = ? and role = ?";
            //2.执行sql
            user = template.queryForObject(sql, new BeanPropertyRowMapper<User>(User.class), userAccount, userPassword, role);
        } catch (Exception e) {

        }

        return user;
    }
}
