import streamlit as st
import pickle
import pandas as pd
import requests

st.set_page_config(page_title = "Movie Verse", page_icon="🎬", layout="wide")

st.markdown('<link rel="preconnect" href="https://fonts.googleapis.com"><link rel="preconnect" href="https://fonts.gstatic.com" crossorigin><link href="https://fonts.googleapis.com/css2?family=Roboto&display=swap" rel="stylesheet">', unsafe_allow_html=True)
st.markdown('<link href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-1BmE4kWBq78iYhFldvKuhfTAU6auU8tT94WrHftjDbrCEXSU1oBoqyl2QvZ6jIW3" crossorigin="anonymous">', unsafe_allow_html=True)


def fetch_poster(moive_id):
     response = requests.get('https://api.themoviedb.org/3/movie/{}?api_key=92d26a4bb89b0966d33e47f5ada74d37&language=en-US'.format(moive_id))
     data = response.json()
     return 'https://image.tmdb.org/t/p/w500/' + data['poster_path']

def recommendTOP5(movie):
     movie_index = movies[movies['title'] == movie].index[0]
     distances = similarity[movie_index]
     movies_list = sorted(list(enumerate(distances)), reverse=True, key=lambda x: x[1])[1:6]

     recommended_movies = []
     recommended_movies_posters = []
     for i in movies_list:
          movie_id = movies.iloc[i[0]].movie_id
          recommended_movies.append(movies.iloc[i[0]].title)
          recommended_movies_posters.append(fetch_poster(movie_id))
     return recommended_movies, recommended_movies_posters


def displaySomeMovies(movie):
    movie_index = movies[movies['title'] == movie].index[0]
    distances = similarity[movie_index]
    movies_list = sorted(list(enumerate(distances)), reverse=True, key=lambda x: x[1])[1:21]

    recommended_movies = []
    recommended_movies_posters = []
    for i in movies_list:
        movie_id = movies.iloc[i[0]].movie_id
        recommended_movies.append(movies.iloc[i[0]].title)
        recommended_movies_posters.append(fetch_poster(movie_id))
    return recommended_movies, recommended_movies_posters

# CSS code
hide_streamlit_style = """
<style>
#MainMenu {visibility: hidden;}
footer {visibility: hidden;}
* {font-family: 'Fira Code', sans-serif;}
div.css-183lzff{
font-family: 'Fira Code', sans-serif;
font-size:15px;
text-align:center;
}
div.css-j5r0tf
{
    margin-top:20px;
}
</style>

"""
st.markdown(hide_streamlit_style, unsafe_allow_html=True)

movies_dict = pickle.load(open('movies_dict.pkl', 'rb'))
movies = pd.DataFrame(movies_dict)

similarity = pickle.load(open('similarity.pkl', 'rb'))

st.title('Movie Verse')

selected_movie_name = st.selectbox(
     'Select a movie', movies['title'].values)

if st.button("Recommend movie"):
    names1, posters1 = recommendTOP5(selected_movie_name)

    col1, col2, col3, col4, col5  = st.columns(5)

    with col1:
            st.text(names1[0])
            st.image(posters1[0])

    with col2:
            st.text(names1[1])
            st.image(posters1[1])

    with col3:
            st.text(names1[2])
            st.image(posters1[2])

    with col4:
            st.text(names1[3])
            st.image(posters1[3])

    with col5:
            st.text(names1[4])
            st.image(posters1[4])
else:
    names, posters = displaySomeMovies(selected_movie_name)

    col1, col2, col3, col4, col5  = st.columns(5)

    with col1:
            st.text(names[0])
            st.image(posters[0])

    with col2:
            st.text(names[1])
            st.image(posters[1])

    with col3:
            st.text(names[2])
            st.image(posters[2])

    with col4:
            st.text(names[3])
            st.image(posters[3])

    with col5:
            st.text(names[4])
            st.image(posters[4])


    col6, col7, col8, col9, col10 = st.columns(5)
    with col6:
            st.text(names[5])
            st.image(posters[5])

    with col7:
            st.text(names[6])
            st.image(posters[6])

    with col8:
            st.text(names[7])
            st.image(posters[7])

    with col9:
            st.text(names[8])
            st.image(posters[8])

    with col10:
        st.text(names[9])
        st.image(posters[9])
    # st.write('You selected:', option)

    col11, col12, col13, col14, col15  = st.columns(5)
    with col11:
        st.text(names[10])
        st.image(posters[10])

    with col12:
        st.text(names[11])
        st.image(posters[11])

    with col13:
        st.text(names[12])
        st.image(posters[12])

    with col14:
        st.text(names[13])
        st.image(posters[13])

    with col15:
        st.text(names[14])
        st.image(posters[14])

    col16, col17, col18, col19, col20 = st.columns(5)
    with col16:
        st.text(names[15])
        st.image(posters[15])

    with col17:
        st.text(names[16])
        st.image(posters[16])

    with col18:
        st.text(names[17])
        st.image(posters[17])

    with col19:
        st.text(names[18])
        st.image(posters[18])

    with col20:
        st.text(names[19])
        st.image(posters[19])


st.markdown("""
<script src="https://code.jquery.com/jquery-3.2.1.slim.min.js" integrity="sha384-KJ3o2DKtIkvYIK3UENzmM7KCkRr/rE9/Qpg6aAZGJwFDMVNA/GpGFF93hXpG5KkN" crossorigin="anonymous"></script>
<script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.12.9/umd/popper.min.js" integrity="sha384-ApNbgh9B+Y1QKtv3Rn7W3mgPxhU9K/ScQsAP7hUibX39j7fakFPskvXusvfa0b4Q" crossorigin="anonymous"></script>
<script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/js/bootstrap.min.js" integrity="sha384-JZR6Spejh4U02d8jOt6vLEHfe/JQGiRRSQQxSfFWpi1MquVdAyjUar5+76PVCmYl" crossorigin="anonymous"></script>
""", unsafe_allow_html=True)