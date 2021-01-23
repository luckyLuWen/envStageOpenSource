package cn.envStage.dao.impl;

import cn.envStage.dao.DevicesNumDao;
import cn.envStage.domain.Devices_num;
import cn.envStage.util.JDBCUtils;
import org.springframework.jdbc.core.BeanPropertyRowMapper;
import org.springframework.jdbc.core.JdbcTemplate;

public class DevicesNumDaoImpl implements DevicesNumDao {

    private JdbcTemplate template = new JdbcTemplate(JDBCUtils.getDataSource());

    @Override
    public Devices_num findAllDevicesNum() {

        Devices_num devices_num = null;
        int userID = 00001;

        try {
            //1.定义sql
            String sql = "select * from devices_num where userID = ?";
            //2.执行sql
            devices_num = template.queryForObject(sql, new BeanPropertyRowMapper<Devices_num>(Devices_num.class), userID);
        } catch (Exception e) {

        }

        return devices_num;
    }
}
