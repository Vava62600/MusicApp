package com.vava.mapp

import androidx.test.core.app.ActivityScenario
import androidx.test.ext.junit.runners.AndroidJUnit4
import androidx.test.filters.LargeTest
import androidx.test.rule.ActivityTestRule
import androidx.test.espresso.Espresso.onView
import androidx.test.espresso.action.ViewActions.click
import androidx.test.espresso.assertion.ViewAssertions.matches
import androidx.test.espresso.matcher.ViewMatchers.*

import org.junit.Rule
import org.junit.Test
import org.junit.runner.RunWith

@RunWith(AndroidJUnit4::class)
@LargeTest
class MainActivityTest {

    @get:Rule
    val activityRule = ActivityTestRule(MainActivity::class.java)

    @Test
    fun testButtonAddEffect_isDisplayed() {
        onView(withId(R.id.btnAddEffect)).check(matches(isDisplayed()))
    }

    @Test
    fun testButtonAddEffect_clickable() {
        onView(withId(R.id.btnAddEffect)).perform(click())
        // Vérifiez si l'action du clic est effectuée, comme l'affichage d'un message
    }

    @Test
    fun testMainScreen_textIsDisplayed() {
        onView(withText("Bienvenue sur MApp pour Android")).check(matches(isDisplayed()))
    }

    // Ajoutez d'autres tests pour les interactions de l'interface utilisateur
}
