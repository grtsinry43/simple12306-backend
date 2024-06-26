/**
 *
 *  Tickets.h
 *  DO NOT EDIT. This file is generated by drogon_ctl
 *
 */

#pragma once
#include <drogon/orm/Result.h>
#include <drogon/orm/Row.h>
#include <drogon/orm/Field.h>
#include <drogon/orm/SqlBinder.h>
#include <drogon/orm/Mapper.h>
#include <drogon/orm/BaseBuilder.h>
#ifdef __cpp_impl_coroutine
#include <drogon/orm/CoroMapper.h>
#endif
#include <trantor/utils/Date.h>
#include <trantor/utils/Logger.h>
#include <json/json.h>
#include <string>
#include <string_view>
#include <memory>
#include <vector>
#include <tuple>
#include <stdint.h>
#include <iostream>

namespace drogon
{
namespace orm
{
class DbClient;
using DbClientPtr = std::shared_ptr<DbClient>;
}
}
namespace drogon_model
{
namespace simple12306
{

class Tickets
{
  public:
    struct Cols
    {
        static const std::string _id;
        static const std::string _title;
        static const std::string _from;
        static const std::string _to;
        static const std::string _start_date;
        static const std::string _end_date;
        static const std::string _price;
        static const std::string _train_type;
        static const std::string _type_1;
        static const std::string _type_2;
        static const std::string _type_3;
        static const std::string _type_4;
    };

    static const int primaryKeyNumber;
    static const std::string tableName;
    static const bool hasPrimaryKey;
    static const std::string primaryKeyName;
    using PrimaryKeyType = int32_t;
    const PrimaryKeyType &getPrimaryKey() const;

    /**
     * @brief constructor
     * @param r One row of records in the SQL query result.
     * @param indexOffset Set the offset to -1 to access all columns by column names,
     * otherwise access all columns by offsets.
     * @note If the SQL is not a style of 'select * from table_name ...' (select all
     * columns by an asterisk), please set the offset to -1.
     */
    explicit Tickets(const drogon::orm::Row &r, const ssize_t indexOffset = 0) noexcept;

    /**
     * @brief constructor
     * @param pJson The json object to construct a new instance.
     */
    explicit Tickets(const Json::Value &pJson) noexcept(false);

    /**
     * @brief constructor
     * @param pJson The json object to construct a new instance.
     * @param pMasqueradingVector The aliases of table columns.
     */
    Tickets(const Json::Value &pJson, const std::vector<std::string> &pMasqueradingVector) noexcept(false);

    Tickets() = default;

    void updateByJson(const Json::Value &pJson) noexcept(false);
    void updateByMasqueradedJson(const Json::Value &pJson,
                                 const std::vector<std::string> &pMasqueradingVector) noexcept(false);
    static bool validateJsonForCreation(const Json::Value &pJson, std::string &err);
    static bool validateMasqueradedJsonForCreation(const Json::Value &,
                                                const std::vector<std::string> &pMasqueradingVector,
                                                    std::string &err);
    static bool validateJsonForUpdate(const Json::Value &pJson, std::string &err);
    static bool validateMasqueradedJsonForUpdate(const Json::Value &,
                                          const std::vector<std::string> &pMasqueradingVector,
                                          std::string &err);
    static bool validJsonOfField(size_t index,
                          const std::string &fieldName,
                          const Json::Value &pJson,
                          std::string &err,
                          bool isForCreation);

    /**  For column id  */
    ///Get the value of the column id, returns the default value if the column is null
    const int32_t &getValueOfId() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<int32_t> &getId() const noexcept;
    ///Set the value of the column id
    void setId(const int32_t &pId) noexcept;

    /**  For column title  */
    ///Get the value of the column title, returns the default value if the column is null
    const std::string &getValueOfTitle() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getTitle() const noexcept;
    ///Set the value of the column title
    void setTitle(const std::string &pTitle) noexcept;
    void setTitle(std::string &&pTitle) noexcept;

    /**  For column from  */
    ///Get the value of the column from, returns the default value if the column is null
    const std::string &getValueOfFrom() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getFrom() const noexcept;
    ///Set the value of the column from
    void setFrom(const std::string &pFrom) noexcept;
    void setFrom(std::string &&pFrom) noexcept;

    /**  For column to  */
    ///Get the value of the column to, returns the default value if the column is null
    const std::string &getValueOfTo() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getTo() const noexcept;
    ///Set the value of the column to
    void setTo(const std::string &pTo) noexcept;
    void setTo(std::string &&pTo) noexcept;

    /**  For column start_date  */
    ///Get the value of the column start_date, returns the default value if the column is null
    const ::trantor::Date &getValueOfStartDate() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<::trantor::Date> &getStartDate() const noexcept;
    ///Set the value of the column start_date
    void setStartDate(const ::trantor::Date &pStartDate) noexcept;

    /**  For column end_date  */
    ///Get the value of the column end_date, returns the default value if the column is null
    const ::trantor::Date &getValueOfEndDate() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<::trantor::Date> &getEndDate() const noexcept;
    ///Set the value of the column end_date
    void setEndDate(const ::trantor::Date &pEndDate) noexcept;

    /**  For column price  */
    ///Get the value of the column price, returns the default value if the column is null
    const std::string &getValueOfPrice() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getPrice() const noexcept;
    ///Set the value of the column price
    void setPrice(const std::string &pPrice) noexcept;
    void setPrice(std::string &&pPrice) noexcept;

    /**  For column train_type  */
    ///Get the value of the column train_type, returns the default value if the column is null
    const int32_t &getValueOfTrainType() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<int32_t> &getTrainType() const noexcept;
    ///Set the value of the column train_type
    void setTrainType(const int32_t &pTrainType) noexcept;

    /**  For column type_1  */
    ///Get the value of the column type_1, returns the default value if the column is null
    const int32_t &getValueOfType1() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<int32_t> &getType1() const noexcept;
    ///Set the value of the column type_1
    void setType1(const int32_t &pType1) noexcept;

    /**  For column type_2  */
    ///Get the value of the column type_2, returns the default value if the column is null
    const int32_t &getValueOfType2() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<int32_t> &getType2() const noexcept;
    ///Set the value of the column type_2
    void setType2(const int32_t &pType2) noexcept;
    void setType2ToNull() noexcept;

    /**  For column type_3  */
    ///Get the value of the column type_3, returns the default value if the column is null
    const int32_t &getValueOfType3() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<int32_t> &getType3() const noexcept;
    ///Set the value of the column type_3
    void setType3(const int32_t &pType3) noexcept;
    void setType3ToNull() noexcept;

    /**  For column type_4  */
    ///Get the value of the column type_4, returns the default value if the column is null
    const int32_t &getValueOfType4() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<int32_t> &getType4() const noexcept;
    ///Set the value of the column type_4
    void setType4(const int32_t &pType4) noexcept;
    void setType4ToNull() noexcept;


    static size_t getColumnNumber() noexcept {  return 12;  }
    static const std::string &getColumnName(size_t index) noexcept(false);

    Json::Value toJson() const;
    Json::Value toMasqueradedJson(const std::vector<std::string> &pMasqueradingVector) const;
    /// Relationship interfaces
  private:
    friend drogon::orm::Mapper<Tickets>;
    friend drogon::orm::BaseBuilder<Tickets, true, true>;
    friend drogon::orm::BaseBuilder<Tickets, true, false>;
    friend drogon::orm::BaseBuilder<Tickets, false, true>;
    friend drogon::orm::BaseBuilder<Tickets, false, false>;
#ifdef __cpp_impl_coroutine
    friend drogon::orm::CoroMapper<Tickets>;
#endif
    static const std::vector<std::string> &insertColumns() noexcept;
    void outputArgs(drogon::orm::internal::SqlBinder &binder) const;
    const std::vector<std::string> updateColumns() const;
    void updateArgs(drogon::orm::internal::SqlBinder &binder) const;
    ///For mysql or sqlite3
    void updateId(const uint64_t id);
    std::shared_ptr<int32_t> id_;
    std::shared_ptr<std::string> title_;
    std::shared_ptr<std::string> from_;
    std::shared_ptr<std::string> to_;
    std::shared_ptr<::trantor::Date> startDate_;
    std::shared_ptr<::trantor::Date> endDate_;
    std::shared_ptr<std::string> price_;
    std::shared_ptr<int32_t> trainType_;
    std::shared_ptr<int32_t> type1_;
    std::shared_ptr<int32_t> type2_;
    std::shared_ptr<int32_t> type3_;
    std::shared_ptr<int32_t> type4_;
    struct MetaData
    {
        const std::string colName_;
        const std::string colType_;
        const std::string colDatabaseType_;
        const ssize_t colLength_;
        const bool isAutoVal_;
        const bool isPrimaryKey_;
        const bool notNull_;
    };
    static const std::vector<MetaData> metaData_;
    bool dirtyFlag_[12]={ false };
  public:
    static const std::string &sqlForFindingByPrimaryKey()
    {
        static const std::string sql="select * from " + tableName + " where id = $1";
        return sql;
    }

    static const std::string &sqlForDeletingByPrimaryKey()
    {
        static const std::string sql="delete from " + tableName + " where id = $1";
        return sql;
    }
    std::string sqlForInserting(bool &needSelection) const
    {
        std::string sql="insert into " + tableName + " (";
        size_t parametersCount = 0;
        needSelection = false;
            sql += "id,";
            ++parametersCount;
        if(dirtyFlag_[1])
        {
            sql += "title,";
            ++parametersCount;
        }
        if(dirtyFlag_[2])
        {
            sql += "from,";
            ++parametersCount;
        }
        if(dirtyFlag_[3])
        {
            sql += "to,";
            ++parametersCount;
        }
        if(dirtyFlag_[4])
        {
            sql += "start_date,";
            ++parametersCount;
        }
        if(dirtyFlag_[5])
        {
            sql += "end_date,";
            ++parametersCount;
        }
        if(dirtyFlag_[6])
        {
            sql += "price,";
            ++parametersCount;
        }
        if(dirtyFlag_[7])
        {
            sql += "train_type,";
            ++parametersCount;
        }
        if(dirtyFlag_[8])
        {
            sql += "type_1,";
            ++parametersCount;
        }
        if(dirtyFlag_[9])
        {
            sql += "type_2,";
            ++parametersCount;
        }
        if(dirtyFlag_[10])
        {
            sql += "type_3,";
            ++parametersCount;
        }
        if(dirtyFlag_[11])
        {
            sql += "type_4,";
            ++parametersCount;
        }
        needSelection=true;
        if(parametersCount > 0)
        {
            sql[sql.length()-1]=')';
            sql += " values (";
        }
        else
            sql += ") values (";

        int placeholder=1;
        char placeholderStr[64];
        size_t n=0;
        sql +="default,";
        if(dirtyFlag_[1])
        {
            n = snprintf(placeholderStr,sizeof(placeholderStr),"$%d,",placeholder++);
            sql.append(placeholderStr, n);
        }
        if(dirtyFlag_[2])
        {
            n = snprintf(placeholderStr,sizeof(placeholderStr),"$%d,",placeholder++);
            sql.append(placeholderStr, n);
        }
        if(dirtyFlag_[3])
        {
            n = snprintf(placeholderStr,sizeof(placeholderStr),"$%d,",placeholder++);
            sql.append(placeholderStr, n);
        }
        if(dirtyFlag_[4])
        {
            n = snprintf(placeholderStr,sizeof(placeholderStr),"$%d,",placeholder++);
            sql.append(placeholderStr, n);
        }
        if(dirtyFlag_[5])
        {
            n = snprintf(placeholderStr,sizeof(placeholderStr),"$%d,",placeholder++);
            sql.append(placeholderStr, n);
        }
        if(dirtyFlag_[6])
        {
            n = snprintf(placeholderStr,sizeof(placeholderStr),"$%d,",placeholder++);
            sql.append(placeholderStr, n);
        }
        if(dirtyFlag_[7])
        {
            n = snprintf(placeholderStr,sizeof(placeholderStr),"$%d,",placeholder++);
            sql.append(placeholderStr, n);
        }
        if(dirtyFlag_[8])
        {
            n = snprintf(placeholderStr,sizeof(placeholderStr),"$%d,",placeholder++);
            sql.append(placeholderStr, n);
        }
        if(dirtyFlag_[9])
        {
            n = snprintf(placeholderStr,sizeof(placeholderStr),"$%d,",placeholder++);
            sql.append(placeholderStr, n);
        }
        if(dirtyFlag_[10])
        {
            n = snprintf(placeholderStr,sizeof(placeholderStr),"$%d,",placeholder++);
            sql.append(placeholderStr, n);
        }
        if(dirtyFlag_[11])
        {
            n = snprintf(placeholderStr,sizeof(placeholderStr),"$%d,",placeholder++);
            sql.append(placeholderStr, n);
        }
        if(parametersCount > 0)
        {
            sql.resize(sql.length() - 1);
        }
        if(needSelection)
        {
            sql.append(") returning *");
        }
        else
        {
            sql.append(1, ')');
        }
        LOG_TRACE << sql;
        return sql;
    }
};
} // namespace simple12306
} // namespace drogon_model
