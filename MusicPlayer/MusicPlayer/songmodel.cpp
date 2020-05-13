#include "songmodel.h"
#include "QDebug"

SongModel::SongModel(QObject * parent):QAbstractListModel(parent)
{

}
void SongModel::addSong(const Song &song)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    listSong << song;
    endInsertRows();
//    emit listupdated();
}

QVariant SongModel::data(const QModelIndex & index, int role) const {
    if (index.row() < 0 || index.row() >= listSong.count())
        return QVariant();

    const Song &song = listSong[index.row()];
    if (role == name)
        return song.getSongName();
    if(role == path)
        return song.getPath();
    if(role == artist)
        return song.getArtist();
    if(role == album)
        return song.getAlbum();
    return QVariant();
}

//void SongModel::setFilterString(QString string)
//{
//    this->setFilterCaseSensitivity(Qt::CaseInsensitive);
//    this->setFilterFixedString(string);
//}

void SongModel::list_music(QString music)
{

//    listSong.append(music);
//    for (QList<Song>::iterator it = listSong.begin(); it != listSong.end(); it++) {
//              qDebug()<<it->getSongName();
//        }
//    emit listupdated();
    Song song(music);
    addSong(song);
}

void SongModel::getCurrentSongIndex(QString name)
{
    qDebug()<<"index = "<<listSong.indexOf(name);
    m_index=listSong.indexOf(name);
}

void SongModel::removeCurrentItem()
{
    listSong.removeAt(m_index);
    qDebug()<<"Clear";
    emit currentItemRemoved(m_index);
}
int SongModel::rowCount(const QModelIndex & parent) const {
    Q_UNUSED(parent)
    return listSong.count();
}
QHash<int, QByteArray> SongModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[name] = "name";
    roles[path] = "path";
    roles[artist] = "artist";
    roles[album] = "album";
    return roles;
}

FilterProxyModel::FilterProxyModel(QObject *parent)
    : QSortFilterProxyModel(parent)
{
    setSortOrder(false);
}

FilterProxyModel::~FilterProxyModel()
{

}

void FilterProxyModel::setFilterString(QString string)
{
    this->setFilterCaseSensitivity(Qt::CaseInsensitive);
    this->setFilterFixedString(string);

}

void FilterProxyModel::setSortOrder(bool checked)
{
    if(checked)
    {
        this->sort(0, Qt::DescendingOrder);
    }
    else
    {
        this->sort(0, Qt::AscendingOrder);
    }
}

void FilterProxyModel::clear(int index)
{
    this->removeRow(index);
}

